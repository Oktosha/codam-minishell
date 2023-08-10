/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/30 15:02:03 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/10 13:28:22 by codespace     ########   odam.nl         */
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
