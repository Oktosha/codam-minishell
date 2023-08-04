/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_a.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:01:09 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/04 15:08:47 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	l_ep_init_so_far(t_ep_so_far *so_far)
{
	so_far->status = EP_SUCCESS;
	so_far->head = NULL;
	so_far->token.type = EP_EMPTY;
	so_far->token.length = 0;
	so_far->state = EP_ST_START;
	so_far->token.data = NULL;
}

void	l_ep_token_dup(t_ep_so_far *sfar, t_lx_token *lxt, t_ep_token_type etk)
{
	sfar->token.type = etk;
	sfar->token.length = lxt->length;
	sfar->token.data = lxt->data;
	l_ep_token_copy(sfar);
}

void	l_ep_replace_token_2(t_lx_token *lx_token, t_ep_so_far *so_far)
{
	if (lx_token->type == LX_OTHER)
		l_ep_token_dup(so_far, lx_token, EP_WORD);
	if (lx_token->type == LX_QUOTE_1)
		l_ep_token_dup(so_far, lx_token, EP_QUOTE_1);
	if (lx_token->type == LX_QUOTE_2)
		l_ep_token_dup(so_far, lx_token, EP_QUOTE_2);
	if (lx_token->type == LX_VARIABLE)
		l_ep_token_dup(so_far, lx_token, EP_WORD);
	if (lx_token->type == LX_WHITESPACE)
		return ;
	if (lx_token->type == LX_WORD)
		l_ep_token_dup(so_far, lx_token, EP_WORD);
	if (lx_token->type == LX_PIPE)
		l_ep_token_dup(so_far, lx_token, EP_PIPE);
}

void	l_ep_replace_token(t_li_node *lx_tk, t_ep_so_far *so_far)
{
	t_lx_token	*lx_token;

	while (lx_tk)
	{
		lx_token = lx_tk->data;
		if (lx_token->type == LX_BAD)
			l_ep_token_dup(so_far, lx_token, EP_BAD);
		if (lx_token->type == LX_HEREDOC)
			l_ep_token_dup(so_far, lx_token, EP_HEREDOC);
		if (lx_token->type == LX_APPEND)
			l_ep_token_dup(so_far, lx_token, EP_APPEND);
		if (lx_token->type == LX_OUTPUT)
			l_ep_token_dup(so_far, lx_token, EP_OUTPUT);
		if (lx_token->type == LX_EMPTY)
			l_ep_token_dup(so_far, lx_token, EP_EMPTY);
		if (lx_token->type == LX_EOL)
			l_ep_token_dup(so_far, lx_token, EP_EOL);
		if (lx_token->type == LX_INPUT)
			l_ep_token_dup(so_far, lx_token, EP_INPUT);
		l_ep_replace_token_2(lx_token, so_far);
		lx_tk = lx_tk->next;
	}
}

t_ep_result	ep_expand(t_ks_kotistate *kotistate, t_li_node *lx_tokens)
{
	t_ep_result	result;
	t_ep_so_far	so_far;

	(void) kotistate;
	result.tokens = NULL;
	result.status = EP_SUCCESS;
	l_ep_init_so_far(&so_far);
	l_ep_replace_token(lx_tokens, &so_far);
	l_ep_token_result(&result, &so_far);
	return (result);
}
