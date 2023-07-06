/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:31:04 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/06 16:08:44 by evoronin      ########   odam.nl         */
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

void	li_print_list(t_li_node *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("[%d]: %s\n", list->data);
		list->data = list->next;
	}
}
