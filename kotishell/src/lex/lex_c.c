/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_c.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 12:57:58 by codespace     #+#    #+#                 */
/*   Updated: 2023/08/25 14:25:18 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

bool	l_lx_closed_quotes_check(t_li_node *tk_tk)
{
	t_tk_token	*token;
	int			count;

	count = 0;
	while (tk_tk->next != NULL)
	{
		token = tk_tk->data;
		if (token->type == TK_QUOTE_1 || token->type == TK_QUOTE_2)
			count++;
		tk_tk = tk_tk->next;
	}
	printf("count: %d\n", count);
	if (count % 2 == 0)
		return (true);
	return (false);
}

t_lx_state	l_lx_next_state(t_tk_token_type type)
{
	if (type == TK_EOL)
		return (LX_ST_END);
	if (type == TK_WORD)
		return (LX_ST_WORD);
	if (type == TK_WHITESPACE)
		return (LX_ST_WHITESPACE);
	if (type == TK_DOLLAR)
		return (LX_ST_VARIABLE);
	if (type == TK_GREAT)
		return (LX_ST_IMPORTANT);
	if (type == TK_LESS)
		return (LX_ST_IMPORTANT);
	if (type == TK_NEWLINE)
		return (LX_ST_IMPORTANT);
	if (type == TK_OTHER)
		return (LX_ST_OTHER);
	if (type == TK_PIPE)
		return (LX_ST_IMPORTANT);
	if (type == TK_QUOTE_1)
		return (LX_ST_QUOTE_1);
	if (type == TK_QUOTE_2)
		return (LX_ST_QUOTE_2);
	if (type == TK_QUESTION)
		return (LX_ST_IMPORTANT);
	return (LX_ST_ERROR);
}

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

void	l_lx_err_unclosed_quote(t_lx_so_far *so_far)
{
	so_far->status = LX_ERR_SYNTAX;
	mini_putstr_fd("unexpected EOF while looking for matching `", 2);
	mini_write(2, so_far->token.data, so_far->token.length);
	mini_putstr_fd("'", 2);
	mini_putstr_fd("\n", 2);
	lx_token_free(so_far->head);
	so_far->head = NULL;
}

void	lx_token_free(t_li_node *list)
{
	t_li_node	*temp;

	while (list)
	{
		temp = list;
		free(temp->data);
		list = list->next;
		free(temp);
	}
	free(list);
}
