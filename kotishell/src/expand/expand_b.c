/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_b.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 18:00:38 by evoronin      #+#    #+#                 */
/*   Updated: 2023/08/21 14:13:09 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	l_ep_whitespace(t_lx_node_lx_token_ptr *lx_res, t_ep_so_far *so_far)
{
	t_lx_token	*cur_lx;

	cur_lx = lx_res->token;
	if (so_far->status != EP_SUCCESS)
		return ;
	if (lx_res->next != NULL)
	{
		lx_res = lx_res->next;
		cur_lx = lx_res->token;
		so_far->state = l_ep_next_state(cur_lx->type);
		so_far->token.type = EP_EMPTY;
		so_far->token.length = 0;
	}
	else
		so_far->state = EP_ST_END;
}

void	l_ep_init_so_far(t_ep_so_far *so_far)
{
	so_far->status = EP_SUCCESS;
	so_far->head = NULL;
	so_far->token.type = EP_EMPTY;
	so_far->token.length = 0;
	so_far->state = EP_ST_START;
	so_far->token.data = NULL;
}

void	ep_token_free(t_ep_node_ep_token_ptr *list)
{
	t_ep_node_ep_token_ptr	*temp;
	t_ep_token				*ep_tk;

	while (list)
	{
		temp = list;
		ep_tk = temp->token;
		free(ep_tk->data);
		free(temp->token);
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

	ptr_token = mini_malloc(sizeof(t_ep_token));
	if (!ptr_token)
	{
		so_far->status = EP_ERR_MALLOC;
		return ;
	}
	ptr_token->data = mini_substr(so_far->token.data, so_far->token.length);
	ptr_token->length = so_far->token.length;
	ptr_token->type = so_far->token.type;
	if (li_new_stack((void *)&so_far->head, ptr_token) == -1)
	{
		so_far->status = EP_ERR_MALLOC;
		free(ptr_token);
		return ;
	}
}
