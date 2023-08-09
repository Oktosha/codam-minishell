/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:17:18 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/09 16:24:53 by evoronin      ########   odam.nl         */
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
	if (li_new_stack(&so_far->head, so_far->cmd) == -1)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
}

void	l_ps_cmd(t_li_node *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*tk;

	tk = ep_tk->data;
	if (so_far->status != PS_SUCCESS)
		return ;
	if (so_far->cmd_length == 0)
	{
		so_far->cmd_data = tk->data;
		so_far->cmd_length += tk->length;
	}
	l_ps_cmd_copy(so_far);
	ep_tk = ep_tk->next;
	tk = ep_tk->data;
	so_far->state = l_ps_next_state(tk->type);
	so_far->cmd_length = 0;
}

void	l_ps_pipe(t_li_node *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*tk;

	if (so_far->status != PS_SUCCESS)
		return ;
	ep_tk = ep_tk->next;
	tk = ep_tk->data;
	so_far->state = l_ps_next_state(tk->type);
	so_far->cmd_length = 0;
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
	{
		so_far->state = PS_ST_END;
		l_ps_end(so_far);
	}
	if (ep_token->type == EP_PIPE)
	{
		so_far->state = PS_ST_PIPE;
		l_ps_pipe(ep_tk, so_far);
	}
}

t_ps_result	ps_parse(t_li_node *ep_tk)
{
	t_ps_result	result;
	t_ps_so_far	so_far;

	result.cmds = NULL;
	result.status = PS_SUCCESS;
	l_ps_start(ep_tk, &so_far);
	while (ep_tk->next != NULL)
	{
		ep_tk = ep_tk->next;
		if (so_far.state == PS_ST_COMMAND)
			l_ps_cmd(ep_tk, &so_far);
		else if (so_far.state == PS_ST_PIPE)
			l_ps_pipe(ep_tk, &so_far);
	}
	l_ps_end(&so_far);
	l_ps_result(&result, &so_far);
	return (result);
}
