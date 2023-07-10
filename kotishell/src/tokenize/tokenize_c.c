/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/10 14:12:29 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/10 16:18:47 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	tk_final_token(t_tk_so_far *so_far, char *s)
{
	t_tk_symbol_type	symbol;

	symbol = s_tk_get_symbol_type(*s + 1);
	if (symbol == TK_SY_EOL && so_far->token.type == TK_EOL)
		return (1);
	if (symbol == TK_SY_WHITESPACE && so_far->token.type == TK_WHITESPACE)
		return (1);
	if (symbol == TK_SY_LETTER && so_far->token.type == TK_WORD)
		return (1);
	return (0);
}
