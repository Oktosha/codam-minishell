/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:31:04 by evoronin      #+#    #+#                 */
/*   Updated: 2023/06/30 15:42:50 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	li_list_free(t_li_node *list)
{
	t_li_node	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}
