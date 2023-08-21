/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:17:18 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/21 20:33:25 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	l_ps_add_argv(t_ps_so_far *so_far)
{
	char				*cmd_arg;

	cmd_arg = mini_substr(so_far->cmd_data, so_far->cmd_length);
	if (!cmd_arg)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
	if (li_new_stack(&so_far->cmd.argvs, cmd_arg) == -1)
	{
		so_far->status = PS_ERR_MALLOC;
		free(cmd_arg);
		return ;
	}
	so_far->cmd_length = 0;
	so_far->cmd_data = NULL;
}

void	l_ps_add_option(t_ps_so_far *so_far)
{
	char	*new;

	new = mini_substr(so_far->cmd_data, so_far->cmd_length);
	if (!new)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
	if (li_new_stack(&so_far->cmd.argvs, new) == -1)
	{
		so_far->status = PS_ERR_MALLOC;
		free(new);
		return ;
	}
}

void	l_ps_cmd_copy(t_ps_so_far *so_far)
{
	t_ps_single_command	*cmd;

	cmd = mini_malloc(sizeof(t_ps_single_command));
	if (!cmd)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
	*cmd = so_far->cmd;
	if (li_new_stack(&so_far->head, cmd) == -1)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
	l_ps_reset_single_cmd(&so_far->cmd);
}

void	l_ps_start(t_ep_node_ep_token_ptr *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*ep_token;

	ep_token = ep_tk->token;
	l_ps_init_so_far(so_far);
	if (ep_token->type == EP_WORD)
	{
		so_far->state = PS_ST_COMMAND;
		l_ps_cmd(ep_tk, so_far);
	}
	if (ep_token->type == EP_PIPE)
	{
		so_far->state = PS_ST_PIPE;
		l_ps_pipe(ep_tk, so_far);
	}
	if (ep_token->type == EP_WHITESPACE)
	{
		so_far->state = PS_ST_WHITESPACE;
		l_ps_whitespace(ep_tk, so_far);
	}
}

t_ps_result	ps_parse(t_ep_node_ep_token_ptr *ep_tk)
{
	t_ps_result	result;
	t_ps_so_far	so_far;

	result.cmds = NULL;
	result.status = PS_SUCCESS;
	l_ps_start(ep_tk, &so_far);
	while (ep_tk)
	{
		ep_tk = ep_tk->next;
		if (so_far.state == PS_ST_COMMAND)
			l_ps_cmd(ep_tk, &so_far);
		else if (so_far.state == PS_ST_PIPE)
			l_ps_pipe(ep_tk, &so_far);
		else if (so_far.state == PS_ST_WHITESPACE)
			l_ps_whitespace(ep_tk, &so_far);
	}
	l_ps_end(&so_far);
	l_ps_result(&result, &so_far);
	return (result);
}
