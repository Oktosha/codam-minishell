/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:17:18 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/30 17:13:23 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	l_ep_token_copy(t_ps_so_far *so_far)
{
	t_ps_single_command	*ptr_cmd;

	ptr_cmd = malloc(sizeof(t_ps_single_command));
	if (!ptr_cmd)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
	ptr_cmd->argv = so_far->cmd.argv;
	ptr_token->length = so_far->token.length;
	ptr_token->type = so_far->token.type;
	if (li_new_stack(&so_far->head, ptr_token) == -1)
	{
		so_far->status = EP_ERR_MALLOC;
		free(ptr_token);
		return ;
	}
}

void	l_ps_init_so_far(t_ps_so_far *so_far)
{
	so_far->status = PS_SUCCESS;
	so_far->head = NULL;
	so_far->cmd.argv = NULL;
	so_far->cmd.inputs = NULL;
	so_far->cmd.outputs = NULL;
	so_far->cmd.appends = NULL;
	so_far->cmd.heredoc = NULL;
	so_far->state = PS_ST_START;
}

void	l_ps_cmd_dup(t_ps_so_far *so_far, t_ep_token *ep_token, t_ep_token_type ps_tk)
{
	so_far->cmd.argv = ep_token->data;
	so_far->cmd.inputs = ep_token->length;
	l_ep_token_copy(so_far);
}

void	l_ps_replace_cmd(t_li_node *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*ep_token;

	while (ep_tk)
	{
		ep_tk = ep_tk->data;
		if (ep_token->type == EP_HEREDOC)
		l_ep_token_dup(so_far, ep_token, PS_HEREDOC);
	}
}

t_ps_result	ps_parse(t_li_node *ep_tk)
{
	t_ps_result	result;
	t_ps_so_far so_far;

	result.cmds = NULL;
	result.status = PS_SUCCESS;
	l_ps_init_so_far(&so_far);
	l_ps_replace_cmd(ep_tk, &so_far);
	l_ps_result(&result, &so_far);
	return (result);
}
