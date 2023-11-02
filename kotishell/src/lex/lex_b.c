/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_b.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 12:08:29 by codespace     #+#    #+#                 */
/*   Updated: 2023/08/25 14:05:50 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

void	l_lx_whitespace(t_li_node *tk_tk, t_lx_so_far *so_far)
{
	t_tk_token	*token;

	if (so_far->status != LX_SUCCESS)
		return ;
	token = tk_tk->data;
	so_far->token.type = LX_WHITESPACE;
	so_far->token.length = token->length;
	so_far->token.data = token->data;
	l_lx_token_copy(so_far);
	if (so_far->status == LX_ERR_MALLOC)
		return ;
	if (tk_tk->next != NULL)
	{
		tk_tk = tk_tk->next;
		token = tk_tk->data;
	}
	else
	{
		so_far->state = LX_ST_END;
		return ;
	}
	if (l_lx_next_state(token->type) != so_far->state)
	{
		so_far->token.type = LX_EMPTY;
		so_far->token.length = 0;
		so_far->state = l_lx_next_state(token->type);
	}
}

void	l_lx_word(t_li_node *tk_tk, t_lx_so_far *so_far)
{
	t_tk_token	*token;

	if (so_far->status != LX_SUCCESS)
		return ;
	token = tk_tk->data;
	so_far->token.type = LX_WORD;
	so_far->token.length = token->length;
	so_far->token.data = token->data;
	if (tk_tk->next == NULL)
	{
		l_lx_token_copy(so_far);
		so_far->state = LX_ST_END;
		return ;
	}
	tk_tk = tk_tk->next;
	token = tk_tk->data;
	if (l_lx_next_state(token->type) != so_far->state)
	{
		l_lx_token_copy(so_far);
		so_far->token.type = LX_EMPTY;
		so_far->token.length = 0;
		so_far->state = l_lx_next_state(token->type);
	}
}

void	l_lx_quotes_2(t_lx_so_far *so_far, t_tk_result *tk_res)
{
	t_li_node	*tk_tk;
	t_tk_token	*tk_token;

	tk_tk = tk_res->tokens;
	if (so_far->status != LX_SUCCESS)
		return ;
	while (tk_res)
	{
		tk_token = tk_tk->data;
		while (tk_token->type != TK_QUOTE_2)
		{
			so_far->token.type = LX_QUOTE_2;
			so_far->token.data = tk_token->data;
			so_far->token.length += tk_token->length;
		}
		tk_tk = tk_res->tokens->next;
	}
}

void	l_lx_token_result(t_lx_result *result, t_lx_so_far *so_far)
{
	result->tokens = so_far->head;
	result->status = so_far->status;
}

void	l_lx_token_copy(t_lx_so_far *so_far)
{
	t_lx_token	*ptr_token;

	ptr_token = mini_malloc(sizeof(t_lx_token));
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
