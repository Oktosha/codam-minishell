/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:17:18 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 18:10:51 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_ps_result	ps_parse(t_li_node *tokens)
{
	t_ps_result	result;

	(void) tokens;
	result.cmds = NULL;
	result.status = PS_SUCCESS;
	printf("I AM PARSE\n");
	return (result);
}

void	ps_cmds_free(t_li_node *list)
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
