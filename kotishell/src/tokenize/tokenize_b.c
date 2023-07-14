/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_b.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:23:10 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/14 13:21:53 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_tk_symbol_type	s_tk_get_symbol_type(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (TK_SY_WHITESPACE);
	if (c == '\0')
		return (TK_SY_EOL);
	return (TK_SY_LETTER);
}

void	s_tk_init_so_far(t_tk_so_far *so_far)
{
	so_far->status = TK_SUCCESS;
	so_far->head = NULL;
	so_far->token.type = TK_EMPTY;
	so_far->token.length = 0;
	so_far->state = TK_ST_START;
	so_far->token.data = NULL;
}

void	s_tk_word(t_tk_so_far *so_far, char *s, t_tk_result *result)
{
	if (so_far->token.type == TK_EMPTY)
	{
		so_far->token.length = 1;
		so_far->token.type = TK_WORD;
		so_far->token.data = s;
	}
	else
		so_far->token.length += 1;
	if (s_tk_next_state(so_far->state, s + 1) != so_far->state)
	{
		s_tk_token_copy(so_far, result);
		if (so_far->status == TK_ERR_MALLOC)
			s_tk_error(so_far, result);
		so_far->token.length = 0;
		so_far->token.type = TK_EMPTY;
		so_far->state = s_tk_next_state(so_far->state, s + 1);
	}
}

void	s_tk_token_copy(t_tk_so_far *so_far, t_tk_result *result)
{
	t_tk_token	*ptr_token;

	ptr_token = malloc(sizeof(t_tk_token));
	if (!ptr_token)
	{
		so_far->status = TK_ERR_MALLOC;
		return ;
	}
	ptr_token->data = so_far->token.data;
	ptr_token->length = so_far->token.length;
	ptr_token->type = so_far->token.type;
	li_new_stack(&so_far->head, ptr_token);
	if (!so_far->head)
	{
		so_far->status = TK_ERR_MALLOC;
		return ;
	}
	s_tk_token_result(result, so_far);
}

void	s_tk_token_result(t_tk_result *result, t_tk_so_far *so_far)
{
	result->tokens = so_far->head;
	if (!result->tokens)
	{
		so_far->status = TK_ERR_MALLOC;
		return ;
	}
	result->status = so_far->status;
}
