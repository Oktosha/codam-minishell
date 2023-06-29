/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_a.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:20:23 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/06/29 18:11:44 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static	t_tk_symbol_type	s_tk_get_symbol_type(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (TK_SY_WHITESPACE);
	if (c == '\0')
		return (TK_SY_EOL);
	return (TK_SY_LETTER);
}

static void 

static void	s_tk_start(t_tk_so_far *so_far, t_tk_state *state, char *s)
{
	t_tk_symbol_type	symbol;

	so_far->head = NULL;
	so_far->last.type = TK_EMPTY;
	so_far->last.length = 0;
	so_far->last.data = NULL;
	so_far->error = NULL;
	symbol = s_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
	{
		*state = TK_ST_END;
		return ;
	}
		////////
		////////
		// not in end, it can be word or space: if (error then do nothing, just return)
}

static t_tk_result	s_tk_end(t_tk_so_far *so_far)
{
	// error copy to end result
	// if error, free
}

t_tk_result	tk_tokenize(char *s)
{
	t_tk_so_far		so_far;
	t_tk_state		state;

	state = TK_ST_START;
	while (*s != '\0')
	{
		if (state == TK_ST_START)
			s_tk_start(&so_far, &state, s);
		else if (state == TK_ST_WHITESPACE)
			s_tk_whitespace(&so_far, &state, s);
		else if (state == TK_ST_WORD)
			s_tk_word(&so_far, &state, s);
		s++;
	}
	if (state == TK_ST_START)
		s_tk_start(&so_far, &state, s);
	else if (state == TK_ST_WHITESPACE)
		s_tk_whitespace(&so_far, &state, s);
	else if (state == TK_ST_WORD)
		s_tk_word(&so_far, &state, s);
	return (s_tk_end(&so_far));
}
