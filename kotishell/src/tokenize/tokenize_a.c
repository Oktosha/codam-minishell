/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_a.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:20:23 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/06/30 19:28:01 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	s_tk_word(t_tk_so_far *so_far, char *s)
{
	t_li_node	*list;
	t_li_node	*node;

	node = NULL;
	if (so_far->token.length == 0)
	{
		list = li_new_list(*s);
		so_far->head->data = list->data;
		so_far->tail->data = list->data;
		so_far->token.type = TK_WORD;
		so_far->token.length += 1;
		so_far->token.data = list->data;
	}
	else
	{
		so_far->head->data = li_add_back(so_far->tail->data, node, *s);
		so_far->tail->data = li_add_back(so_far->tail->data, node, *s);
		so_far->token.type = TK_WORD;
		so_far->token.length += 1;
		so_far->token.data = li_add_back(so_far->tail->data, node, *s);
	}
	printf("%s\n", so_far->token.data);
}

static void	s_tk_whitespace(t_tk_so_far *so_far, char *s)
{
	t_tk_symbol_type	symbol;

	symbol = s_tk_get_symbol_type(*s);
	so_far->token.type = TK_WHITESPACE;
}

static t_tk_result	s_tk_end(t_tk_so_far *so_far, char *s)
{
	so_far->token.type = TK_EOL;
	so_far->token.length = 1;
	so_far->tail->data = *s;
	so_far->tail->next = NULL;
}

static void	s_tk_start(t_tk_so_far *so_far, t_tk_state *state, char *s)
{
	t_tk_symbol_type	symbol;

	s_tk_init_so_far(so_far);
	symbol = s_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
	{
		*state = TK_ST_END;
		s_tk_end(so_far, s);
	}
	if (symbol == TK_SY_LETTER)
	{
		*state = TK_ST_WORD;
		s_tk_word(so_far, s);
	}
	if (symbol == TK_SY_WHITESPACE)
	{
		*state = TK_ST_WHITESPACE;
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
	state = TK_ST_START;
	while (i > 0)
	{
		if (state == TK_ST_START)
			s_tk_start(&so_far, &state, s);
		else if (state == TK_ST_WHITESPACE)
			s_tk_whitespace(&so_far, s);
		else if (state == TK_ST_WORD)
			s_tk_word(&so_far, s);
		s++;
		i--;
	}
	return (result);
}
