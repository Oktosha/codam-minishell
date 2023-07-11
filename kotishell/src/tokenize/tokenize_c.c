/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/10 14:12:29 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/11 19:35:40 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_tk_state	tk_next_state(t_tk_state state, char *s)
{
	t_tk_symbol_type	symbol;

	symbol = s_tk_get_symbol_type(*s + 1);
	if (symbol == TK_SY_EOL)
		state = TK_ST_END;
	if (symbol == TK_SY_WHITESPACE)
		state = TK_ST_WHITESPACE;
	if (symbol == TK_SY_LETTER)
		state = TK_ST_WORD;
	return (state);
}
