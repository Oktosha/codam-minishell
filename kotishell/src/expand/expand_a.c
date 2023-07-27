/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_a.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:01:09 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/27 18:13:53 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

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

void	l_ep_init_so_far(t_lx_so_far *so_far)
{
	so_far->status = EP_SUCCESS;
	so_far->head = NULL;
	so_far->token.type = EP_EMPTY;
	so_far->token.length = 0;
	so_far->state = EP_ST_START;
	so_far->token.data = NULL;
}

void	l_ep_token_dup(t_ep_so_far *so_far, t_lx_token *lx_token, t_ep_token_type ep_tk)
{
	so_far->token.type = ep_tk;
	so_far->token.length = lx_token->length;
	so_far->token.data = lx_token->data;
	l_ep_token_copy(so_far);
}
void	l_ep_replace_token(t_li_node *lx_tk, t_lx_so_far *so_far)
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
		if (lx_token->type == LX_OTHER)
			l_ep_token_dup(so_far, lx_token, EP_WORD);
		if (lx_token->type == LX_QUOTE_1)
			l_ep_token_dup(so_far, lx_token, EP_QUOTE_1);
		if (lx_token->type == LX_QUOTE_2)
			l_ep_token_dup(so_far, lx_token, EP_QUOTE_2);
	}
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
