/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_a.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:19:41 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 15:31:08 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

t_lx_result	lx_lex(t_tk_result *tokens)
{
	t_lx_result	result;

	result.tokens = NULL;
	result.status = LX_SUCCESS;
	printf("I AM LEX\n");
	return (result);
}
