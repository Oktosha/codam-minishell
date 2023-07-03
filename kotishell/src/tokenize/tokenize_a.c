/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_a.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:20:23 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/03 17:12:18 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	s_tk_word(t_tk_so_far *so_far, char *s)
{
	if (so_far->token.type != TK_WORD && so_far->token.length == 0)
	{
		so_far->head = li_new_list(s);
		so_far->tail = li_new_list(s);
		so_far->token.type = TK_WORD;
		so_far->token.length = 1;
		so_far->token.data = mini_substr(s, s, so_far->token.length);
	}
	else if (so_far->token.type == TK_WORD && so_far->token.length > 0)
	{
		so_far->token.length += 1;
		so_far->token.data = mini_substr(so_far->token.data, 0, so_far->token.length);
	}
	printf("%s\n", so_far->token.data);
}

static void	s_tk_whitespace(t_tk_so_far *so_far, char *s)
{
	if (so_far->token.type == TK_WHITESPACE)
	{
		so_far->token.length += 1;
		so_far->token.data = mini_substr(s, );
		so_far->status = TK_SUCCESS;
	}
	if (so_far->token.type != TK_WHITESPACE)
	{
		so_far->token.type = TK_WHITESPACE;
		so_far->token.length = 1;
		so_far->token.data = mini_substr();
		so_far->tail->data = li_new_stack(so_far->tail->data, s);
		so_far->tail->next = NULL;
		so_far->status = TK_SUCCESS;
	}
}

static void	s_tk_end(t_tk_so_far *so_far, t_tk_result result, char *s)
{
	if (so_far->token.type != TK_EOL)
	{
		so_far->token.type = TK_EOL;
		so_far->token.length = 1;
		so_far->token.data = li_new_stack(result.tokens, s);
		so_far->status = TK_SUCCESS;
	}
}

static void	s_tk_start(t_tk_so_far *so_far, t_tk_result	result, t_tk_state	state, char *s)
{
	t_tk_symbol_type	symbol;

	s_tk_init_so_far(so_far);
	symbol = s_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
	{
		state = TK_ST_END;
		s_tk_end(so_far, result, s);
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
	else
		return ;
}

t_tk_result	tk_tokenize(char *s)
{
	t_tk_so_far		so_far;
	t_tk_state		state;
	t_tk_result		result;
	int				i;

	i = mini_strlen(s);
	result.tokens = NULL;
	state = TK_ST_START;
	while (i >= 0)
	{
		if (state == TK_ST_START)
			s_tk_start(&so_far, result, state, s);
		else if (state == TK_ST_WHITESPACE)
			s_tk_whitespace(&so_far, result, state, s);
		else if (state == TK_ST_WORD)
			s_tk_word(&so_far, result, s);
		s++;
		i--;
	}
	result.status = TK_SUCCESS;
	return (result);
}
