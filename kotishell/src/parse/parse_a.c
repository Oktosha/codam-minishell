/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:17:18 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/01 17:50:54 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	l_ps_cmd_copy(t_ps_so_far *so_far)
{
	char				*cmd_arg;

	cmd_arg = mini_substr(so_far->cmd_data, so_far->cmd_length);
	if (!cmd_arg)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
	if (li_new_stack(&so_far->cmd->argv, cmd_arg) == -1)
	{
		so_far->status = PS_ERR_MALLOC;
		free(cmd_arg);
		return ;
	}
	if (li_new_stack(&so_far->head, &so_far->cmd->argv) == -1)
	{
		so_far->status = PS_ERR_MALLOC;
		free(cmd_arg);
		return ;
	}
}

void	l_ps_cmd(t_li_node *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*tk;

	tk = ep_tk->data;
	if (so_far->status != PS_SUCCESS)
		return ;
	so_far->cmd_data = tk->data;
	so_far->cmd_length = tk->length;
	ep_tk = ep_tk->next;
	tk = ep_tk->data;
	if (tk->type == EP_PIPE || tk->type == EP_EOL)
	{
		l_ps_cmd_copy(so_far);
		return ;
	}
	if (tk->type == EP_WHITESPACE)
	{
		ep_tk = ep_tk->next;
		return ;
	}
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
}

void	l_ps_start(t_li_node *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*ep_token;

	ep_token = ep_tk->data;
	l_ps_init_so_far(so_far);
	if (ep_token->type == EP_WORD)
	{
		so_far->state = PS_ST_COMMAND;
		l_ps_cmd(ep_tk, so_far);
	}
	if (ep_token->type == EP_EOL)
		return ;
}

t_ps_result	ps_parse(t_li_node *ep_tk)
{
	t_ps_result	result;
	t_ps_so_far	so_far;

	result.cmds = NULL;
	result.status = PS_SUCCESS;
	l_ps_start(ep_tk, &so_far);
	l_ps_end(&so_far);
	l_ps_result(&result, &so_far);
	return (result);
}
