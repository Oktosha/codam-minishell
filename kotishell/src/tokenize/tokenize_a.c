/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_a.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:20:23 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/04 19:07:40 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	s_tk_word(t_tk_so_far *so_far, char *s)
{
	if (so_far->token.type != TK_WORD && so_far->token.length == 0)
	{
		so_far->token.length = 1;
		so_far->token.type = TK_WORD;
	}
	else
		so_far->token.length += 1;
	so_far->token.data = mini_substr(s, 0, so_far->token.length);
	printf("head: %s\n", (char *)so_far->head->data);
	so_far->head->data = li_new_stack(so_far->head, so_far->token.data);
	so_far->head->next = NULL;
	free(so_far->token.data);
	so_far->status = TK_SUCCESS;
}

static void	s_tk_whitespace(t_tk_so_far *so_far, char *s)
{
	if (so_far->token.type == !TK_WHITESPACE && so_far->token.length == 0)
	{
		so_far->token.type = TK_WHITESPACE;
		so_far->token.length = 1;
	}
	else
		so_far->token.length += 1;
	so_far->token.data = mini_substr(s, 0, so_far->token.length);
	printf("2%s\n", so_far->token.data);
	so_far->head->data = li_new_stack(so_far->head, so_far->token.data);
	so_far->head->next = NULL;
	free(so_far->token.data);
	so_far->status = TK_SUCCESS;
}

static void	s_tk_end(t_tk_so_far *so_far, char *s)
{
		mini_putstr_fd("here\n", 1);
	if (so_far->token.type != TK_EOL)
	{
		so_far->token.type = TK_EOL;
		so_far->token.length = 1;
		printf("1%s\n", so_far->token.data);
		so_far->token.data = mini_substr(s, 0, so_far->token.length);
		so_far->head->data = li_new_stack(so_far->head, so_far->token.data);
		so_far->head->next = NULL;
		so_far->status = TK_SUCCESS;
	}
	///do I need an else statement in case we have several EOL characters?
	//is this even possible?
}

static void	s_tk_start(t_tk_so_far *so_far, t_tk_state	state, char *s)
{
	t_tk_symbol_type	symbol;

	s_tk_init_so_far(so_far);
	symbol = s_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
	{
		state = TK_ST_END;
		s_tk_end(so_far, s);
		printf("[1]: %s\n", so_far->token.data);
	}
	if (symbol == TK_SY_LETTER)
	{
		state = TK_ST_WORD;
		s_tk_word(so_far, s);
		printf("[2]: %s\n", so_far->token.data);
	}
	if (symbol == TK_SY_WHITESPACE)
	{
		state = TK_ST_WHITESPACE;
		s_tk_whitespace(so_far, s);
		printf("[3]: %s\n", so_far->token.data);
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

	result.tokens = NULL;
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
	while (so_far.head->next != NULL)
	{
		result.tokens = li_new_stack(result.tokens, so_far.head->data);
		so_far.head->data = so_far.head->next;
	}
	printf("3%s\n", (char *)so_far.head->data);
	result.status = so_far.status;
	return (result);
}
