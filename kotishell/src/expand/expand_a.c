/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_a.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:01:09 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/21 16:47:28 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	l_ep_end(t_lx_node_lx_token_ptr *lx_res, t_ep_so_far *so_far)
{
	if (so_far->status == EP_ERR_MALLOC)
		l_ep_error_cleanup(lx_res, so_far);
}

void	l_ep_word(t_lx_node_lx_token_ptr *lx_res, t_ep_so_far *so_far)
{
	t_lx_token	*cur_lx;
	t_lx_token	*next_lx;

	if (so_far->status != EP_SUCCESS)
		return ;
	cur_lx = lx_res->token;
	if (so_far->token.type == EP_EMPTY)
	{
		so_far->token.data = cur_lx->data;
		so_far->token.type = EP_WORD;
	}
	so_far->token.length += cur_lx->length;
	next_lx = lx_res->next->token;
	so_far->state = l_ep_next_state(next_lx->type);
	if (so_far->state != EP_ST_WORD)
	{
		l_ep_token_copy(so_far);
		if (so_far->status == EP_ERR_MALLOC)
			return ;
		so_far->token.type = EP_EMPTY;
		so_far->token.length = 0;
	}
}

void	l_ep_pipe(t_lx_node_lx_token_ptr *lx_res, t_ep_so_far *so_far)
{
	t_lx_token	*cur_lx;
	t_lx_token	*next_lx;

	cur_lx = lx_res->token;
	if (so_far->status != EP_SUCCESS)
		return ;
	so_far->token.type = EP_PIPE;
	so_far->token.length = cur_lx->length;
	so_far->token.data = cur_lx->data;
	l_ep_token_copy(so_far);
	if (so_far->status == EP_ERR_MALLOC)
		return ;
	next_lx = lx_res->next->token;
	so_far->state = l_ep_next_state(next_lx->type);
	so_far->token.type = EP_EMPTY;
	so_far->token.length = 0;
}

void	l_ep_start(t_lx_node_lx_token_ptr *lx_res, t_ep_so_far *so_far)
{
	t_lx_token	*lx_token;

	lx_token = lx_res->token;
	if (lx_token->type == LX_WORD || lx_token->type == LX_OTHER)
	{
		so_far->state = EP_ST_WORD;
		l_ep_word(lx_res, so_far);
	}
	if (lx_token->type == LX_PIPE)
	{
		so_far->state = EP_ST_PIPE;
		l_ep_pipe(lx_res, so_far);
	}
	if (lx_token->type == LX_WHITESPACE)
	{
		so_far->state = EP_ST_WHITESPACE;
		l_ep_whitespace(lx_res, so_far);
	}
}

t_ep_result	ep_expand(t_ks_kotistate *kotistate, t_lx_node_lx_token_ptr *lx_res)
{
	t_ep_result	result;
	t_ep_so_far	so_far;

	(void) kotistate;
	result.tokens = NULL;
	result.status = EP_SUCCESS;
	l_ep_init_so_far(&so_far);
	l_ep_start(lx_res, &so_far);
	while (lx_res)
	{
		lx_res = lx_res->next;
		if (so_far.state == EP_ST_WORD)
			l_ep_word(lx_res, &so_far);
		if (so_far.state == EP_ST_PIPE)
			l_ep_pipe(lx_res, &so_far);
		if (so_far.state == EP_ST_WHITESPACE)
			l_ep_whitespace(lx_res, &so_far);
	}
	l_ep_end(lx_res, &so_far);
	l_ep_token_result(&result, &so_far);
	return (result);
}
