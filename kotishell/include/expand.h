/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 19:57:44 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 17:30:59 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that expands variables after tokenizing.
 * Namespace prefix: "ep".
*/
#ifndef EXPAND_H
# define EXPAND_H
# include "kotistate.h"
# include "lex.h"
# include "lists.h"

typedef enum e_ep_status
{
	EP_SUCCESS = 0,
	EP_ERR_MALLOC,
}	t_ep_status;

typedef struct s_ep_result
{
	t_li_node	*tokens;
	t_ep_status	status;
}	t_ep_result;

t_ep_result	ep_expand(t_ks_kotistate *state, t_li_node *tokens);
void		ep_token_free(t_li_node *list);

#endif
