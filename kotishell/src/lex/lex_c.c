/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_c.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 12:57:58 by codespace     #+#    #+#                 */
/*   Updated: 2023/08/01 17:53:24 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

void	l_lx_err_unclosed_quote(t_lx_so_far *so_far)
{
	so_far->status = LX_ERR_SYNTAX;
	mini_putstr_fd("Syntax error, unclosed quote\n", 2);
}
