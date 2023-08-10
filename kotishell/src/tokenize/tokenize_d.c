/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_d.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 17:12:15 by evoronin      #+#    #+#                 */
/*   Updated: 2023/08/10 16:48:29 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_tk_state	l_tk_next_state(t_tk_state state, char *s)
{
	t_tk_symbol_type	symbol;

	(void)(state);
	symbol = l_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
		return (TK_ST_END);
	if (symbol == TK_SY_WHITESPACE)
		return (TK_ST_WHITESPACE);
	if (symbol == TK_SY_ALPHANUM)
		return (TK_ST_WORD);
	if (symbol == TK_SY_IMPORTANT || symbol == TK_SY_NEWLINE)
		return (TK_ST_IMPORTANT);
	if (symbol == TK_SY_OTHER)
		return (TK_ST_OTHER);
	if (symbol == TK_SY_BAD)
		return (TK_ST_ERROR);
	return (TK_ST_ERROR);
}

t_tk_token_type	l_tk_get_token_type(char c)
{
	if (c == '\0')
		return (TK_EOL);
	if (c == '|')
		return (TK_PIPE);
	if (c == '"')
		return (TK_QUOTE_2);
	if (c == '\'')
		return (TK_QUOTE_1);
	if (c == '$')
		return (TK_DOLLAR);
	if (c == '<')
		return (TK_LESS);
	if (c == '>')
		return (TK_GREAT);
	if (c == '?')
		return (TK_QUESTION);
	if (c == '\n')
		return (TK_NEWLINE);
	return (TK_BAD);
}

t_tk_symbol_type	l_tk_get_symbol_type(char c)
{
	if (c == '\0')
		return (TK_SY_EOL);
	if (c == '"' || c == '$' || c == '\'' || c == '<' || c == '>' || c == '?'
		|| c == '|' || c == '\n')
		return (TK_SY_IMPORTANT);
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (TK_SY_WHITESPACE);
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (TK_SY_ALPHANUM);
	if (c >= 32 && c <= 126)
		return (TK_SY_OTHER);
	return (TK_SY_BAD);
}

void	l_tk_symbol_error(t_tk_so_far *so_far)
{
	mini_write(2, so_far->token.data, so_far->token.length);
	mini_putstr_fd(" \033[0;31m\x1B[1m-> Unsupported symbol\n\033[0m", 2);
}
