/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_b.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 18:00:38 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/27 18:00:46 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	ep_token_free(t_li_node *list)
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
