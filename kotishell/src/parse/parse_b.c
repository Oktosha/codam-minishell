/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/30 15:02:03 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/01 17:51:38 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	l_ps_end(t_ps_so_far *so_far)
{
	if (so_far->status == PS_ERR_MALLOC)
		l_ps_error_cleanup(so_far);
	if (so_far->status == PS_ERR_SYNTAX)
		l_ps_syntax_error(so_far);
	else
		return ;
}

void	ps_cmds_free(t_li_node *list)
{
	t_li_node	*temp;

	while (list)
	{
		temp = list;
		free(temp->data);
		list = list->next;
		free(temp);
	}
}

void	l_ps_result(t_ps_result *result, t_ps_so_far *so_far)
{
	result->cmds = so_far->head;
	result->status = so_far->status;
}

void	l_ps_error_cleanup(t_ps_so_far *so_far)
{
	ps_cmds_free(so_far->cmd->argv);
	ps_cmds_free(so_far->cmd->inputs);
	ps_cmds_free(so_far->cmd->outputs);
	so_far->cmd = NULL;
	mini_putstr_fd("Failed malloc\n", 2);
}

void	l_ps_syntax_error(t_ps_so_far *so_far)
{
	mini_putstr_fd(" \033[0;31m\x1B[1m-> syntax error near token \n\033[0m", 2);
	mini_putstr_fd(so_far->cmd->argv->data, 2);
}
