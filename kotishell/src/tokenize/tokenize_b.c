/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_b.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:23:10 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/20 15:38:29 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	l_tk_newline(t_tk_so_far *so_far, char *s)
{
	if (so_far->status != TK_SUCCESS)
		return ;
	if (so_far->token.type == TK_EMPTY)
	{
		so_far->token.length = 1;
		so_far->token.type = TK_OTHER;
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

void	l_tk_other(t_tk_so_far *so_far, char *s)
{
	if (so_far->status != TK_SUCCESS)
		return ;
	if (so_far->token.type == TK_EMPTY)
	{
		so_far->token.length = 1;
		so_far->token.type = TK_OTHER;
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

void	l_tk_word(t_tk_so_far *so_far, char *s)
{
	if (so_far->status != TK_SUCCESS)
		return ;
	if (so_far->token.type == TK_EMPTY)
	{
		so_far->token.length = 1;
		so_far->token.type = TK_WORD;
		so_far->token.data = s;
	}
	else
		so_far->token.length += 1;
	if (l_tk_next_state(so_far->state, s + 1) != so_far->state)
	{
		l_tk_token_copy(so_far);
		if (so_far->status == TK_ERR_MALLOC)
			return ;
		so_far->token.length = 0;
		so_far->token.type = TK_EMPTY;
		so_far->state = l_tk_next_state(so_far->state, s + 1);
	}
}
