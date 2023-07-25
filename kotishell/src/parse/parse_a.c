/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:17:18 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 15:34:55 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_ps_result	ps_parse(t_li_node *tokens)
{
	t_ps_result	result;

	result.cmds = NULL;
	result.status = PS_SUCCESS;
	printf("I AM PARSE\n");
	return (result);
}
