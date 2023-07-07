/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_b.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:23:10 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/07 18:05:27 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_tk_symbol_type	s_tk_get_symbol_type(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
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
	so_far->token.data = NULL;
}

void	s_tk_word(t_tk_so_far *so_far, char *s)
{
	if (so_far->token.type != TK_WORD && so_far->token.length == 0)
	{
		so_far->token.length = 1;
		so_far->token.type = TK_WORD;
		so_far->token.data = s;
	}
	else
		so_far->token.length += 1;
}

void	tk_token_copy(t_tk_so_far *so_far)
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
	so_far->head = li_new_stack(so_far->head, ptr_token);
	if (!so_far->head)
	{
		so_far->status = TK_ERR_MALLOC;
		return ;
	}
	li_print_list(so_far->head);
	printf("\n");
	// write(1, ptr_token->data, ptr_token->length);
}
