/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:36:32 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/22 14:43:36 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	li_list_size(void *data)
{
	int			i;
	t_li_node	*list;

	i = 0;
	list = data;
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
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	li_new_stack(void *void_list, void *data)
{
	t_li_node	*node;
	t_li_node	**ok_list;
	t_li_node	*list;

	ok_list = void_list;
	list = (*ok_list);
	if (!list)
	{
		list = li_new_list(data);
		if (!list)
			return (-1);
		*ok_list = list;
	}
	else
	{
		node = li_new_list(data);
		if (!node)
			return (-1);
		li_add_back(ok_list, node);
	}
	return (0);
}

void	li_add_back(t_li_node **list, t_li_node *node)
{
	t_li_node	*new_list;

	new_list = *list;
	if (!new_list)
	{
		mini_putstr_fd("\033[0;31mBUG\n", 2);
		exit(EXIT_FAILURE);
	}
	while (new_list->next != NULL)
		new_list = new_list->next;
	new_list->next = node;
}
