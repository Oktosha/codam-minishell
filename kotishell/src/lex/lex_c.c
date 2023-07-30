/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_c.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 12:57:58 by codespace     #+#    #+#                 */
/*   Updated: 2023/07/30 14:20:55 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

void	l_lx_err_unclosed_quote(t_lx_so_far *so_far)
{
	so_far->status = LX_ERR_SYNTAX;
	mini_putstr_fd("Syntax error, unclosed quote\n", 2);
}

/**
 * ft only for testing purposes
 * to delete later
*/
void	LX_print_list_test(t_li_node *list)
{
	t_lx_token	*token;
	int			i;

	i = 0;
	while (list)
	{
		token = list->data;
		printf("[%d]: ", i);
		fflush(stdout);
		if (write(1, token->data, token->length) == -1)
			mini_putstr_fd("Write error\n", 2);
		if (write(1, "\n", 2) == -1)
			mini_putstr_fd("Write error\n", 2);
		list = list->next;
		i++;
	}
}
