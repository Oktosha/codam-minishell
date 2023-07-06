/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_b.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:23:10 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/06 18:05:47 by evoronin      ########   odam.nl         */
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
	so_far->head = li_new_stack(so_far->head, NULL);
	if (!so_far->head)
	{
		so_far->status = TK_ERR_MALLOC;
		return ;
	}
	so_far->head->data = mini_malloc(sizeof(t_tk_token));
	if (!so_far->head->data)
	{
		
	}
	// ((t_tk_token *)(so_far->head->data))->type = TK_EMPTY;
	so_far->token.length = 0;
	so_far->token.data = NULL;
	so_far->status = TK_SUCCESS;
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
