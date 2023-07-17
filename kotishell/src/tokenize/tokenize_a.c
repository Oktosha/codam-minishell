/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_a.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:20:23 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/17 14:27:47 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	l_tk_whitespace(t_tk_so_far *so_far, char *s)
{
	if (so_far->status != TK_SUCCESS)
		return ;
	if (so_far->token.type == TK_EMPTY)
	{
		so_far->token.length = 1;
		so_far->token.type = TK_WHITESPACE;
		so_far->token.data = s;
	}
	else
		so_far->token.length += 1;
	if (l_tk_next_state(so_far->state, s + 1) != so_far->state)
	{
		l_tk_token_copy(so_far);
		if (so_far->status == TK_ERR_MALLOC)
			return ;
		so_far->token.type = TK_EMPTY;
		so_far->token.length = 0;
		so_far->state = l_tk_next_state(so_far->state, s + 1);
	}
}

static void	l_tk_end(t_tk_so_far *so_far, char *s)
{
	if (so_far->status == TK_SUCCESS)
	{
		so_far->token.type = TK_EOL;
		so_far->token.length = 0;
		so_far->token.data = s;
		l_tk_token_copy(so_far);
	}
	if (so_far->status == TK_ERR_MALLOC)
		l_tk_error_cleanup(so_far);
}

static void	l_tk_start(t_tk_so_far *so_far, char *s)
{
	t_tk_symbol_type	symbol;

	symbol = l_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
	{
		so_far->state = TK_ST_END;
		l_tk_end(so_far, s);
	}
	if (symbol == TK_SY_LETTER)
	{
		so_far->state = TK_ST_WORD;
		l_tk_word(so_far, s);
	}
	if (symbol == TK_SY_WHITESPACE)
	{
		so_far->state = TK_ST_WHITESPACE;
		l_tk_whitespace(so_far, s);
	}
}

t_tk_result	tk_tokenize(char *s)
{
	t_tk_result		result;
	t_tk_so_far		so_far;
	int				i;

	result.tokens = NULL;
	l_tk_init_so_far(&so_far);
	i = mini_strlen(s);
	l_tk_start(&so_far, s);
	while (i > 0)
	{
		s++;
		if (so_far.state == TK_ST_WORD)
			l_tk_word(&so_far, s);
		else if (so_far.state == TK_ST_WHITESPACE)
			l_tk_whitespace(&so_far, s);
		i--;
	}
	s++;
	l_tk_end(&so_far, s);
	l_tk_token_result(&result, &so_far);
	return (result);
}
