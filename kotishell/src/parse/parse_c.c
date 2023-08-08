/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 14:12:11 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/08 09:24:33 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_ps_state	l_ps_next_state(t_ep_token_type ep_tk)
{
	if (ep_tk == EP_WORD)
		return (PS_ST_COMMAND);
	else if (ep_tk == EP_APPEND || ep_tk == EP_HEREDOC)
		return (PS_ST_INPUT);
	else if (ep_tk == EP_OUTPUT || ep_tk == EP_HEREDOC)
		return (PS_ST_OUTPUT);
	else if (ep_tk == EP_EOL)
		return (PS_ST_END);
	else if (ep_tk == EP_PIPE)
		return (PS_ST_PIPE);
	else if (ep_tk == EP_QUOTE_1 || ep_tk == EP_QUOTE_2)
		return (PS_ST_QUOTE);
	return (PS_ST_ERROR);
}

void	l_ps_init_so_far(t_ps_so_far *so_far)
{
	so_far->status = PS_SUCCESS;
	so_far->head = NULL;
	so_far->cmd = mini_malloc(sizeof(t_ps_single_command));
	so_far->cmd->argv = NULL;
	so_far->cmd->inputs = NULL;
	so_far->cmd->outputs = NULL;
	so_far->cmd_length = 0;
	so_far->state = PS_ST_START;
	so_far->cmd_data = NULL;
	so_far->cmd->pid = -1;
}

void	l_ps_syntax_error(t_ps_so_far *so_far)
{
	mini_putstr_fd(" \033[0;31m\x1B[1m-> syntax error near token \n\033[0m", 2);
	mini_putstr_fd(so_far->cmd->argv->data, 2);
}
