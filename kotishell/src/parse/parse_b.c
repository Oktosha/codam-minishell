/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/30 15:02:03 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/30 15:03:48 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
