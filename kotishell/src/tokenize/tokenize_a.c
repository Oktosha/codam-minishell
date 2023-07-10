/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_a.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:20:23 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/10 15:59:39 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	s_tk_whitespace(t_tk_so_far *so_far, char *s)
{
	if (so_far->token.type != TK_WHITESPACE && so_far->token.length == 0)
	{
		so_far->token.length = 1;
		so_far->token.type = TK_WHITESPACE;
		so_far->token.data = s;
	}
	else
		so_far->token.length += 1;
	tk_token_copy(so_far);
}

static void	s_tk_end(t_tk_so_far *so_far, char *s)
{
	if (so_far->token.type != TK_EOL)
	{
		so_far->token.type = TK_EOL;
		so_far->token.length = 1;
		so_far->token.data = s;
	}
	tk_token_copy(so_far);
}

static void	s_tk_start(t_tk_so_far *so_far, t_tk_state	state, char *s)
{
	t_tk_symbol_type	symbol;

	symbol = s_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
	{
		state = TK_ST_END;
		s_tk_end(so_far, s);
	}
	if (symbol == TK_SY_LETTER)
	{
		state = TK_ST_WORD;
		s_tk_word(so_far, s);
	}
	if (symbol == TK_SY_WHITESPACE)
	{
		state = TK_ST_WHITESPACE;
		s_tk_whitespace(so_far, s);
	}
}

t_tk_result	tk_tokenize(char *s)
{
	t_tk_state		state;
	t_tk_result		result;
	t_tk_so_far		so_far;
	int				i;

	result.tokens = NULL;
	state = TK_ST_START;
	s_tk_init_so_far(&so_far);
	i = mini_strlen(s) + 1;
	while (i >= 0)
	{
		s_tk_start(&so_far, state, s);
		if (tk_final_token(&so_far, s) == 0)
			tk_token_result(&result, &so_far);
		s++;
		i--;
	}
	li_print_list(result.tokens);
	return (result);
}
