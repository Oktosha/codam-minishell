/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/10 14:12:29 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/14 16:05:12 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_tk_state	s_tk_next_state(t_tk_state state, char *s)
{
	t_tk_symbol_type	symbol;

	symbol = s_tk_get_symbol_type(*s);
	if (symbol == TK_SY_EOL)
		state = TK_ST_END;
	if (symbol == TK_SY_WHITESPACE)
		state = TK_ST_WHITESPACE;
	if (symbol == TK_SY_LETTER)
		state = TK_ST_WORD;
	return (state);
}

void	s_tk_print_list(t_li_node *list)
{
	t_tk_token	*token;

	while (list)
	{
		token = list->data;
		if (write(1, token->data, token->length) == -1)
			mini_putstr_fd("Write error\n", 2);
		if (write(1, "\n", 2) == -1)
			mini_putstr_fd("Write error\n", 2);
		list = list->next;
	}
}

void	s_li_token_free(t_li_node *list)
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

void	s_tk_error(t_tk_so_far *so_far, t_tk_result *result)
{
	s_li_token_free(so_far->head);
	s_li_token_free(result->tokens);
	mini_putstr_fd("Failed malloc\n", 2);
}
