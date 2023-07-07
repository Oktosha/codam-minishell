/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_b.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:23:10 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/07 11:00:37 by elenavoroni   ########   odam.nl         */
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
		so_far->status = TK_ERR_MALLOC;
		return ;
	}
	so_far->head->data = NULL;
	so_far->token.type = TK_EMPTY;
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
		printf("%d\n", so_far->token.length);
}

t_li_node	*tk_so_far_copy(t_tk_token token, t_li_node *head)
{
	((t_tk_token *)(head->data))->type = token.type;
	((t_tk_token *)(head->data))->type = TK_EMPTY;
	((t_tk_token *)(head->data))->type = TK_EMPTY;
	return (head->data);
}
