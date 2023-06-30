/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:36:32 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/06/30 16:19:16 by evoronin      ########   odam.nl         */
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

	node = malloc(sizeof(t_li_node));
	if (!node)
		li_list_free(node);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_li_node	*li_new_stack(t_li_node *list)
{
	if (!list)
		list = new_list();
	else
		add_back(list, new_list());
	return (list);
}

t_li_node	*li_add_back(t_li_node *list, t_li_node *node, void *data)
{
	t_li_node	*last;

	if (!list)
		ft_error();
	while (list->next != NULL)
		list = list->next;
	list->data = data;
	list->next = node;
	return (list);
}

void	li_add_front(t_li_node *list, void *data)
{
	t_li_node	*node;

	node = (t_li_node *)malloc(sizeof(t_li_node));
	if (!node)
		return ;
	node->data = data;
	node->next = list;
	list = node;
}
