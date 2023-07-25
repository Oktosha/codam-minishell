/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_a.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:19:41 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 18:41:00 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

t_lx_result	lx_lex(t_li_node *tokens)
{
	t_lx_result	result;

	(void) tokens;
	result.tokens = NULL;
	result.status = LX_SUCCESS;
	printf("I AM LEX\n");
	return (result);
}

void	lx_token_free(t_li_node *list)
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
