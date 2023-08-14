/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_a.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:01:09 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/14 17:06:57 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	l_ep_end(t_li_node *lx_res, t_ep_so_far *so_far)
{
	if (so_far->status == EP_SUCCESS)
		lx_token_free(lx_res);
	if (so_far->status == EP_ERR_MALLOC)
		l_ep_error_cleanup(lx_res, so_far);
}

void	l_ep_word(t_li_node *lx_res, t_ep_so_far *so_far)
{
	t_lx_token	*cur_lx;
	t_lx_token	*next_lx;

	if (so_far->status != EP_SUCCESS)
		return ;
	cur_lx = lx_res->data;
	so_far->token.type = EP_WORD;
	so_far->token.data = cur_lx->data;
	so_far->token.length += cur_lx->length;
	next_lx = lx_res->next->data;
	while (next_lx->type == LX_WORD || next_lx->type == LX_OTHER)
	{
		so_far->token.length += next_lx->length;
		next_lx = lx_res->next->data;
	}
	l_ep_token_copy(so_far);
	if (so_far->status == EP_ERR_MALLOC)
		return ;
	so_far->token.type = EP_EMPTY;
	so_far->token.length = 0;
	so_far->state = l_ep_next_state(next_lx->type);
}

void	l_ep_start(t_li_node *lx_res, t_ep_so_far *so_far)
{
	t_lx_token	*lx_token;

	lx_token = lx_res->data;
	if (lx_token->type == LX_WORD || lx_token->type == LX_OTHER)
	{
		so_far->state = EP_ST_WORD;
		l_ep_word(lx_res, so_far);
	}
}

t_ep_result	ep_expand(t_ks_kotistate *kotistate, t_li_node *lx_res)
{
	t_ep_result	result;
	t_ep_so_far	so_far;

	(void) kotistate;
	result.tokens = NULL;
	result.status = EP_SUCCESS;
	l_ep_init_so_far(&so_far);
	l_ep_start(lx_res, &so_far);
	l_ep_token_result(&result, &so_far);
	return (result);
}
