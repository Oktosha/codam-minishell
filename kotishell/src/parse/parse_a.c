/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:17:18 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/31 15:53:48 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	l_ps_cmd_copy(t_ps_so_far *so_far)
{
	t_ps_single_command	*ptr_cmd;
	char				*cmd_arg;

	cmd_arg = mini_substr(so_far->head, so_far->cmd_length);
	if (!cmd_arg)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
	ptr_cmd = malloc(sizeof(t_ps_single_command));
	if (!ptr_cmd)
	{
		so_far->status = PS_ERR_MALLOC;
		return ;
	}
	if (li_new_stack(&so_far->head, ptr_cmd) == -1)
	{
		so_far->status = EP_ERR_MALLOC;
		free(ptr_cmd);
		return ;
	}
}

void	l_ps_cmd(t_li_node *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*tk;

	if (so_far->status != PS_SUCCESS)
		return ;
	if (so_far->cmd->argv == NULL)
	{
		tk = ep_tk->data;
		so_far->head = tk->data;
		so_far->cmd->argv = tk->data;
		so_far->cmd_length = tk->length;
		l_ps_cmd_copy(so_far);
		ep_tk = ep_tk->next;
	}
	while (tk->type == EP_PIPE)
	{
		if (tk->type == EP_WHITESPACE)
		{
			so_far->head += 1;
			ep_tk = ep_tk->next;
		}
		if (tk->type == EP_WORD)
			so_far->cmd_length += tk->length; 
		
	}
	l_ps_cmd_copy(so_far);
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
