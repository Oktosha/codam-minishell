/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_a.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:20:23 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/14 15:59:05 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	s_tk_whitespace(t_tk_so_far *so_far, char *s, t_tk_result *result)
{
	if (so_far->token.type == TK_EMPTY)
	{
		so_far->token.length = 1;
		so_far->token.type = TK_WHITESPACE;
		so_far->token.data = s;
	}
	else
		so_far->token.length += 1;
	if (s_tk_next_state(so_far->state, s + 1) != so_far->state)
	{
		s_tk_token_copy(so_far, result);
		so_far->token.type = TK_EMPTY;
		so_far->token.length = 0;
		so_far->state = s_tk_next_state(so_far->state, s + 1);
	}
}

static void	s_tk_end(t_tk_so_far *so_far, char *s, t_tk_result *result)
{
	if (so_far->token.type == TK_EMPTY)
	{
		so_far->token.type = TK_EOL;
		so_far->token.length = 0;
		so_far->token.data = s;
	}
	s_tk_token_copy(so_far, result);
	if (so_far->status == TK_ERR_MALLOC)
		s_tk_error(so_far, result);
}

static void	s_tk_start(t_tk_so_far *so_far, char *s, t_tk_result *result)
{
	t_tk_symbol_type	symbol;

	symbol = s_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
	{
		so_far->state = TK_ST_END;
		s_tk_end(so_far, s, result);
	}
	if (symbol == TK_SY_LETTER)
	{
		so_far->state = TK_ST_WORD;
		s_tk_word(so_far, s, result);
	}
	if (symbol == TK_SY_WHITESPACE)
	{
		so_far->state = TK_ST_WHITESPACE;
		s_tk_whitespace(so_far, s, result);
	}
}

t_tk_result	tk_tokenize(char *s)
{
	t_tk_result		result;
	t_tk_so_far		so_far;
	int				i;

	result.tokens = NULL;
	s_tk_init_so_far(&so_far);
	i = mini_strlen(s);
	s_tk_start(&so_far, s, &result);
	while (i > 0)
	{
		s++;
		if (so_far.state == TK_ST_WORD)
			s_tk_word(&so_far, s, &result);
		else if (so_far.state == TK_ST_WHITESPACE)
			s_tk_whitespace(&so_far, s, &result);
		i--;
	}
	s++;
	s_tk_end(&so_far, s, &result);
	return (result);
}
