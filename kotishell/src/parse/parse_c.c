/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 14:12:11 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/18 17:51:17 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	l_ps_cmd(t_li_node *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*tk;

	tk = ep_tk->data;
	if (so_far->status != PS_SUCCESS)
		return ;
	so_far->cmd_data = tk->data;
	so_far->cmd_length += tk->length;
	if (so_far->cmd.argv == NULL)
		l_ps_add_argv(so_far);
	else
		l_ps_add_option(so_far);
	if (ep_tk->next != NULL)
	{
		ep_tk = ep_tk->next;
		tk = ep_tk->data;
		so_far->state = l_ps_next_state(tk->type);
		if (so_far->state != PS_ST_COMMAND)
			l_ps_cmd_copy(so_far);
		so_far->cmd_length = 0;
	}
	else
	{
		l_ps_cmd_copy(so_far);
		so_far->state = PS_ST_END;
	}
}

t_ps_state	l_ps_next_state(t_ep_token_type ep_tk)
{
	if (ep_tk == EP_WORD)
		return (PS_ST_COMMAND);
	if (ep_tk == EP_WHITESPACE)
		return (PS_ST_WHITESPACE);
	if (ep_tk == EP_INPUT || ep_tk == EP_HEREDOC)
		return (PS_ST_INPUT);
	if (ep_tk == EP_OUTPUT || ep_tk == EP_APPEND)
		return (PS_ST_OUTPUT);
	if (ep_tk == EP_PIPE)
		return (PS_ST_PIPE);
	if (ep_tk == EP_QUOTE_1 || ep_tk == EP_QUOTE_2)
		return (PS_ST_QUOTE);
	return (PS_ST_ERROR);
}

void	l_ps_init_so_far(t_ps_so_far *so_far)
{
	so_far->status = PS_SUCCESS;
	so_far->head = NULL;
	so_far->cmd.argv = NULL;
	so_far->cmd.inputs = NULL;
	so_far->cmd.outputs = NULL;
	so_far->cmd_length = 0;
	so_far->state = PS_ST_START;
	so_far->cmd_data = NULL;
	so_far->cmd.pid = -1;
}

void	l_ps_syntax_error(t_ps_so_far *so_far)
{
	mini_putstr_fd(" \033[0;31m\x1B[1m-> syntax error near token \n\033[0m", 2);
	mini_putstr_fd(so_far->cmd.argv->data, 2);
	l_ps_error_cleanup(so_far);
}

void	l_ps_reset_single_cmd(t_ps_single_command *cmd)
{
	cmd->argv = NULL;
	cmd->inputs = NULL;
	cmd->outputs = NULL;
	cmd->pid = -1;
}
