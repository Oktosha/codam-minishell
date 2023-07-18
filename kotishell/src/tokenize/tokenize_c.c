/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/10 14:12:29 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/18 14:14:19 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_tk_state	l_tk_next_state(t_tk_state state, char *s)
{
	t_tk_symbol_type	symbol;

	(void)(state);
	symbol = l_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
		return (TK_ST_END);
	if (symbol == TK_SY_WHITESPACE)
		return (TK_ST_WHITESPACE);
	if (symbol == TK_SY_LETTER)
		return (TK_ST_WORD);
	if (symbol == TK_SY_PIPE)
		return (TK_ST_PIPE);
	return (TK_ST_BUG);
}

void	l_tk_token_free(t_li_node *list)
{
	t_li_node	*temp;

	while (list)
	{
		temp = list;
		free(temp->data);
		list = list->next;
		free(temp);
	}
}

void	l_tk_error_cleanup(t_tk_so_far *so_far)
{
	l_tk_token_free(so_far->head);
	so_far->head = NULL;
	mini_putstr_fd("Failed malloc\n", 2);
}
