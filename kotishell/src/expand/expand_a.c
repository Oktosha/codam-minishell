/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_a.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:01:09 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/27 17:26:59 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	l_ep_token_copy(t_lx_so_far *so_far)
{
	t_ep_token	*ptr_token;

	ptr_token = malloc(sizeof(t_ep_token));
	if (!ptr_token)
	{
		so_far->status = LX_ERR_MALLOC;
		return ;
	}
	ptr_token->data = so_far->token.data;
	ptr_token->length = so_far->token.length;
	ptr_token->type = so_far->token.type;
	if (li_new_stack(&so_far->head, ptr_token) == -1)
	{
		so_far->status = LX_ERR_MALLOC;
		free(ptr_token);
		return ;
	}
}

void	l_lx_init_so_far(t_lx_so_far *so_far)
{
	so_far->status = LX_SUCCESS;
	so_far->head = NULL;
	so_far->token.type = LX_EMPTY;
	so_far->token.length = 0;
	so_far->state = LX_ST_START;
	so_far->token.data = NULL;
}

t_ep_result	ep_expand(t_ks_kotistate *kotistate, t_li_node *tokens)
{
	t_ep_result	result;

	(void) kotistate;
	(void) tokens;
	result.tokens = NULL;
	result.status = EP_SUCCESS;


	return (result);
}

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
