/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:17:18 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/01 09:10:51 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	l_ps_cmd_copy(t_ps_so_far *so_far)
{
	char				*cmd_arg;

	cmd_arg = mini_substr(so_far->head, so_far->cmd->argv);
	if (!cmd_arg)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
	if (li_new_stack(&so_far->head, cmd_arg) == -1)
	{
		so_far->status = EP_ERR_MALLOC;
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
	so_far->cmd->argv = tk->data;
	so_far->cmd_length = tk->length;
	l_ps_cmd_copy(so_far);
	ep_tk = ep_tk->next;
	while (tk->type != EP_PIPE)
	{
		if (tk->type == EP_WHITESPACE)
			ep_tk = ep_tk->next;
		if (tk->type == EP_WORD)
		{
			so_far->cmd->argv = tk->data;
			so_far->cmd_length = tk->length;
			l_ps_cmd_copy(so_far);
			ep_tk = ep_tk->next;
		}
	}
	l_ps_cmd_copy(so_far);
}

void	l_ps_init_so_far(t_ps_so_far *so_far)
{
	so_far->status = PS_SUCCESS;
	so_far->head = NULL;
	so_far->cmd->argv = NULL;
	so_far->cmd->inputs = NULL;
	so_far->cmd->outputs = NULL;
	so_far->cmd->appends = NULL;
	so_far->cmd->heredoc = NULL;
	so_far->state = PS_ST_START;
}

void	l_ps_start(t_ep_token *ep_tk, t_ps_so_far *so_far)
{
	l_ps_init_so_far(&so_far);

	if (ep_tk->type == EP_WORD)
	{
		so_far->state = PS_ST_COMMAND;
		l_ps_cmd(ep_tk, so_far);
	}
}

t_ps_result	ps_parse(t_li_node *ep_tk)
{
	t_ps_result	result;
	t_ps_so_far	so_far;
	t_ep_token	*ep_token;

	result.cmds = NULL;
	result.status = PS_SUCCESS;
	ep_token = ep_tk->data;
	l_ps_start(ep_token, &so_far);
	while (ep_tk)
	{
		ep_token = ep_tk->data;
		if (ep_token->type == EP_WORD)
			l_ps_cmd(ep_token, &so_far);
		ep_tk = ep_tk->next;
	}
	l_ps_end(ep_token, &so_far);
	l_ps_result(&result, &so_far);
	return (result);
}
