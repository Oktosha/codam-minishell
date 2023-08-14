/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_b.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 18:00:38 by evoronin      #+#    #+#                 */
/*   Updated: 2023/08/01 17:56:00 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	ep_token_free(t_li_node *list)
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

void	l_ep_token_result(t_ep_result *result, t_ep_so_far *so_far)
{
	result->tokens = so_far->head;
	result->status = so_far->status;
}

void	l_ep_token_copy(t_ep_so_far *so_far)
{
	t_ep_token	*ptr_token;

	ptr_token = malloc(sizeof(t_ep_token));
	if (!ptr_token)
	{
		so_far->status = EP_ERR_MALLOC;
		return ;
	}
	ptr_token->data = so_far->token.data;
	ptr_token->length = so_far->token.length;
	ptr_token->type = so_far->token.type;
	if (li_new_stack(&so_far->head, ptr_token) == -1)
	{
		so_far->status = EP_ERR_MALLOC;
		free(ptr_token);
		return ;
	}
}
