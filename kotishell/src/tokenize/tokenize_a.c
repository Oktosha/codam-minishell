/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_a.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:20:23 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/05 20:21:10 by elenavoroni   ########   odam.nl         */
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
}

static void	s_tk_end(t_tk_so_far *so_far, char *s)
{
	if (so_far->token.type != TK_EOL)
	{
		so_far->token.type = TK_EOL;
		so_far->token.length = 1;
		so_far->token.data = s;
	}
}

static void	s_tk_start(t_tk_so_far *so_far, t_tk_state	state, char *s)
{
	t_tk_symbol_type	symbol;

	symbol = s_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
	{
		state = TK_ST_END;
		s_tk_end(so_far, s);
		so_far->head = li_new_stack(so_far->head, so_far->token
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

t_tk_result	tk_tokenize(char *s, t_tk_so_far *so_far)
{
	t_tk_state		state;
	int				i;

	state = TK_ST_START;
	i = mini_strlen(s);
	if (i == 0)
	{
		state = TK_ST_START;
		s_tk_start(&so_far, state, s);

	}
	while (i >= 0)
	{
		if (state == TK_ST_START)
			s_tk_start(&so_far, state, s);
		else if (state == TK_ST_WHITESPACE)
			s_tk_whitespace(&so_far, s);
		else if (state == TK_ST_WORD)
			s_tk_word(&so_far, s);
		s++;
		i--;
	}

}

t_tk_result	tk_result(char *s)
{
	t_tk_result		result;
	t_tk_so_far		so_far;

	result.tokens = NULL;
	s_tk_init_so_far(&so_far);
	tk_tokenize(s, &so_far);
	result.status = so_far.status;
	if (result.status == TK_SUCCESS)
	{
		while (so_far.head->next != NULL)
		{
			result.tokens = li_new_stack(result.tokens, so_far.head->data);
			so_far.head->data = so_far.head->next;
		}
	}
	return (result);
}
