/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_b.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:23:10 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/03 11:22:14 by evoronin      ########   odam.nl         */
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

void	s_tk_init_result(t_tk_result result)
{
	t_li_node	tokens;
	t_li_node	status;

	result.tokens = li_new_list(NULL);
	if (!result.tokens)
	{
		li_list_free(result.tokens);
		result.status = TK_ERR_MALLOC;
		exit(EXIT_FAILURE);
	}
	result.status = NULL;
}

void	s_tk_init_so_far(t_tk_so_far *so_far)
{
	so_far->head = NULL;
	so_far->token.type = TK_EMPTY;
	so_far->token.length = 0;
	so_far->token.data = NULL;
	so_far->status = NULL;
	so_far->tail = NULL;
}