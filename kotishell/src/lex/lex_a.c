/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_a.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:19:41 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/22 16:45:23 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

void	l_lx_end(t_li_node *tk_tk, t_lx_so_far *so_far)
{
	t_tk_token	*token;

	token = tk_tk->data;
	if (so_far->status == LX_SUCCESS)
	{
		so_far->token.type = LX_EOL;
		so_far->token.length = 0;
		so_far->token.data = token->data;
		l_lx_token_copy(so_far);
	}
	if (so_far->status == LX_ERR_SYNTAX)
		l_lx_err_unclosed_quote(so_far);
}

void	l_lx_quote_1(t_li_node *tk_tk, t_lx_so_far *so_far)
{
	t_tk_token	*token;

	token = tk_tk->data;
	(void) tk_tk;
	if (so_far->status != LX_SUCCESS)
		return ;
	if (l_lx_closed_quote_check(tk_tk) != 0)
	{
		so_far->status = LX_ERR_SYNTAX;
		return ;
	}
	so_far->token.type = LX_WORD;
	so_far->token.data = token->data;
	while (token->type != TK_QUOTE_2 && tk_tk->next != NULL)
	{
		token = tk_tk->data;
		so_far->token.length += token->length;
		tk_tk = tk_tk->next;
	}
	l_lx_token_copy(so_far);
	if (l_lx_next_state(token->type) != so_far->state)
	{
		l_tk_token_copy(so_far);
		if (so_far->status == TK_ERR_MALLOC)
			return ;
		so_far->token.type = TK_EMPTY;
		so_far->token.length = 0;
		so_far->state = l_tk_next_state(so_far->state, s + 1);
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
	// if (tk_token->type == TK_WORD)
	// {
	// 	so_far->state = LX_ST_WORD;
	// 	l_lx_word(tk_tk, so_far);
	// }
	if (token->type == TK_QUOTE_1)
	{
		so_far->state = LX_ST_QUOTE_1;
		l_lx_quote_1(tk_tk, so_far);
	}
	// if (token->type == TK_QUOTE_2)
	// {
	// 	so_far->state = LX_ST_QUOTE_2;
	// 	l_lx_quote_1(tk_tk, so_far);
	// }
}

t_lx_result	lx_lex(t_li_node *tk_tk)
{
	t_lx_result	result;
	t_lx_so_far	so_far;

	l_lx_init_so_far(&so_far);
	l_lx_start(tk_tk, &so_far);
	while (tk_tk)
	{
		tk_tk = tk_tk->next;
		// if (so_far.state == LX_ST_WORD)
		// 	l_lx_word(tk_tk, &so_far);
		if (so_far.state == LX_ST_QUOTE_1)
			l_lx_quote_1(tk_tk, &so_far);
		// if (so_far.state == LX_ST_QUOTE_2)
		// 	l_lx_quote_2(tk_tk, &so_far);
	}
	l_lx_end(tk_tk, &so_far);
	l_lx_token_result(&result, &so_far);
	return (result);
}
