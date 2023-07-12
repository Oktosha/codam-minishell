/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:31:04 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/12 11:54:09 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "tokenize.h"

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
	t_tk_token	*token;

	while (list)
	{
		token = list->data;
		write(1, token->data, token->length);
		write(1, "\n", 2);
		list = list->next;
	}
}
