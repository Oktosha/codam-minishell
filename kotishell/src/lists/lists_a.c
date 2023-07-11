/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:36:32 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/11 17:22:51 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	li_list_size(t_li_node *list)
{
	int		i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_li_node	*li_new_list(void *data)
{
	t_li_node	*node;

	node = mini_malloc(sizeof(t_li_node));
	node->data = data;
	node->next = NULL;
	return (node);
}

t_li_node	*li_new_stack(t_li_node *list, void *data)
{
	if (!list)
		list = li_new_list(data);
	else
		li_add_back(list, li_new_list(data));
	return (list);
}

t_li_node	*li_add_back(t_li_node *list, t_li_node *node)
{
	t_li_node	*last;

	last = list;
	if (!last)
		exit(EXIT_FAILURE);//TODO exit function
	while (last->next != NULL)
		last = list->next;
	last->next = node;
	return (last);
}
