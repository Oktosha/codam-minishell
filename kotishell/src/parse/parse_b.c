/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/30 15:02:03 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/21 16:09:19 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	l_ps_whitespace(t_ep_node_ep_token_ptr *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*tk;

	tk = ep_tk->data;
	if (so_far->status != PS_SUCCESS)
		return ;
	if (ep_tk->next != NULL)
	{
		ep_tk = ep_tk->next;
		tk = ep_tk->data;
		so_far->state = l_ps_next_state(tk->type);
	}
	else
		so_far->state = PS_ST_END;
}

void	l_ps_end(t_ps_so_far *so_far)
{
	if (so_far->status == PS_ERR_SYNTAX)
		l_ps_syntax_error(so_far);
	if (so_far->status == PS_ERR_MALLOC)
		l_ps_error_cleanup(so_far);
	ps_cmd_argv_free(so_far->cmd.argv);
	ps_cmd_argv_free(so_far->cmd.inputs);
	ps_cmd_argv_free(so_far->cmd.outputs);
}

void	l_ps_result(t_ps_result *result, t_ps_so_far *so_far)
{
	result->cmds = so_far->head;
	result->status = so_far->status;
}

void	l_ps_error_cleanup(t_ps_so_far *so_far)
{
	ps_free_all_cmds(so_far->head);
	so_far->head = NULL;
	mini_putstr_fd("Failed malloc\n", 2);
}

void	l_ps_pipe(t_ep_node_ep_token_ptr *ep_tk, t_ps_so_far *so_far)
{
	t_ep_token	*tk;

	if (so_far->status != PS_SUCCESS)
		return ;
	ep_tk = ep_tk->next;
	tk = ep_tk->data;
	so_far->state = l_ps_next_state(tk->type);
	so_far->cmd_length = 0;
	l_ps_reset_single_cmd(&so_far->cmd);
}
