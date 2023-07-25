/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_a.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:01:09 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 15:57:52 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

t_ep_result	ep_expand(t_ks_kotistate *kotistate, t_li_node *tokens)
{
	t_ep_result	result;

	(void) kotistate;
	(void) tokens;
	result.tokens = NULL;
	result.status = EP_SUCCESS;
	printf("I AM EXPAND\n");
	return (result);
}
