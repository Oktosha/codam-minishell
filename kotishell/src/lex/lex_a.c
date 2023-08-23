/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_a.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:19:41 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/23 14:52:47 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

void	l_lx_quote_1(t_li_node *tk_tk, t_lx_so_far *so_far)
{
	t_tk_token	*token;

	token = tk_tk->data;
	if (so_far->status != LX_SUCCESS)
		return ;
	if (l_lx_closed_quote_check_1(tk_tk) != 0)
	{
		so_far->token.data = token->data;
		so_far->token.length = token->length;
		so_far->token.type = LX_BAD;
		so_far->status = LX_ERR_SYNTAX;
		return ;
	}
	so_far->token.type = LX_WORD;
	so_far->token.data = token->data + 1;
	while (token->type != TK_QUOTE_1 && tk_tk->next != NULL)
	{
		token = tk_tk->data;
		so_far->token.length += token->length;
		tk_tk = tk_tk->next;
	}
	so_far->token.length -= 2;
	l_lx_token_copy(so_far);
	if (so_far->status == LX_ERR_MALLOC)
			return ;
	if (tk_tk->next == NULL)
	{
		so_far->state = LX_ST_END;
		return ;
	}
	tk_tk = tk_tk->next;
	token = tk_tk->data;
	if (l_lx_next_state(token->type) != so_far->state)
	{
		so_far->token.type = LX_EMPTY;
		so_far->token.length = 0;
		so_far->state = l_lx_next_state(token->type);
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

void	l_lx_start(t_li_node *tk_tk, t_lx_so_far *so_far)
{
	t_tk_token	*token;

	token = tk_tk->data;
	if (token->type == TK_WORD)
	{
		so_far->state = LX_ST_WORD;
		l_lx_word(tk_tk, so_far);
	}
	if (token->type == TK_QUOTE_1)
	{
		so_far->state = LX_ST_QUOTE_1;
		l_lx_quote_1(tk_tk, so_far);
	}
}

t_lx_result	lx_lex(t_li_node *tk_tk)
{
	t_lx_result	result;
	t_lx_so_far	so_far;

	l_lx_init_so_far(&so_far);
	l_lx_start(tk_tk, &so_far);
	while (tk_tk->next != NULL)
	{
		tk_tk = tk_tk->next;
		if (so_far.state == LX_ST_WORD)
			l_lx_word(tk_tk, &so_far);
		else if (so_far.state == LX_ST_QUOTE_1)
			l_lx_quote_1(tk_tk, &so_far);
		else if (so_far.state == LX_ST_WHITESPACE)
			l_lx_whitespace(tk_tk, &so_far);
	}
	l_lx_end(tk_tk, &so_far);
	l_lx_token_result(&result, &so_far);
	return (result);
}
