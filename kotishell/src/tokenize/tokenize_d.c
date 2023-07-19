/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_d.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/19 17:12:15 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/19 17:51:13 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

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
	return (TK_BUG);
}

t_tk_symbol_type	l_tk_get_symbol_whitespaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' 
		|| c == '\r')
		return (TK_SY_WHITESPACE);
	if (c == '\n')
		return (TK_SY_NEWLINE);
	return (TK_SY_BUG);
}

t_tk_symbol_type	l_tk_get_symbol_type(char c)
{
	if (c == '"' || c == '$' || c == '\'' || c == '<' || c == '>' || c == '?'
		|| c == '|')
		return (TK_SY_IMPORTANT);
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r' 
		|| c == '\n')
		return (l_tk_get_symbol_whitespaces(c));
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (TK_SY_ALPHANUM);
	if (c >= 32 && c <= 126)
		return (TK_SY_OTHER);
	return (TK_SY_BUG);
}
