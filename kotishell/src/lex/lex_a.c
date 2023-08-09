/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_a.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:19:41 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/09 16:26:36 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

void	l_lx_init_so_far(t_lx_so_far *so_far)
{
	so_far->status = LX_SUCCESS;
	so_far->head = NULL;
	so_far->token.type = LX_EMPTY;
	so_far->token.length = 0;
	so_far->state = LX_ST_START;
	so_far->token.data = NULL;
}

// void	l_lx_start(t_lx_so_far *so_far, t_li_node *tk_tk)
// {
// 	if (tk_token->type == TK_QUOTE_2)
// 	{
// 		so_far->state = LX_ST_QUOTE_2;
// 		so_far->token.data = tk_token->data + 1;
// 	}
// 	tk_tk = tk_tk->next;
// 	if (so_far->token.length == 0)
// 	{
// 		l_lx_err_unclosed_quote(so_far);
// 		return ;
// 	}
// 	else
// 		l_lx_token_copy(so_far);
// 	LX_print_list_test(so_far->head);
// }

void	l_lx_token_dup(t_lx_so_far *sfar, t_tk_token *ttk, t_lx_token_type ltk)
{
	sfar->token.type = ltk;
	sfar->token.length = ttk->length;
	sfar->token.data = ttk->data;
	l_lx_token_copy(sfar);
}

void	l_lx_replace_token_2(t_tk_token	*tk_token, t_lx_so_far *so_far)
{
	if (tk_token->type == TK_QUOTE_2)
		l_lx_token_dup(so_far, tk_token, LX_QUOTE_2);
	if (tk_token->type == TK_QUESTION)
		l_lx_token_dup(so_far, tk_token, LX_OTHER);
	if (tk_token->type == TK_WHITESPACE)
		l_lx_token_dup(so_far, tk_token, LX_WHITESPACE);
	if (tk_token->type == TK_WORD)
		l_lx_token_dup(so_far, tk_token, LX_WORD);
	if (tk_token->type == TK_BAD)
		l_lx_token_dup(so_far, tk_token, LX_BAD);
	if (tk_token->type == TK_EMPTY)
		l_lx_token_dup(so_far, tk_token, LX_EMPTY);
	if (tk_token->type == TK_EOL)
		l_lx_token_dup(so_far, tk_token, LX_EOL);
}

void	l_lx_replace_token(t_li_node *tk_tk, t_lx_so_far *so_far)
{
	t_tk_token	*tk_token;

	while (tk_tk)
	{
		tk_token = tk_tk->data;
		if (tk_token->type == TK_DOLLAR)
			l_lx_token_dup(so_far, tk_token, LX_OTHER);
		if (tk_token->type == TK_GREAT)
			l_lx_token_dup(so_far, tk_token, LX_OUTPUT);
		if (tk_token->type == TK_LESS)
			l_lx_token_dup(so_far, tk_token, LX_INPUT);
		if (tk_token->type == TK_OTHER)
			l_lx_token_dup(so_far, tk_token, LX_OTHER);
		if (tk_token->type == TK_PIPE)
			l_lx_token_dup(so_far, tk_token, LX_PIPE);
		if (tk_token->type == TK_QUOTE_1)
			l_lx_token_dup(so_far, tk_token, LX_QUOTE_1);
		l_lx_replace_token_2(tk_token, so_far);
		tk_tk = tk_tk->next;
	}
}

t_lx_result	lx_lex(t_li_node *tk_tk)
{
	t_lx_result	result;
	t_lx_so_far	so_far;
	// t_tk_token	*tk_token;

	// tk_token = tk_tk->data;
	l_lx_init_so_far(&so_far);
	l_lx_replace_token(tk_tk, &so_far);
	l_lx_token_result(&result, &so_far);
	return (result);
}
