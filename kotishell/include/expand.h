/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 19:57:44 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/27 17:36:58 by evoronin      ########   odam.nl         */
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

typedef enum e_ep_token_type
{
	EP_BAD,
	EP_HEREDOC,
	EP_APPEND,
	EP_OUTPUT,
	EP_EMPTY,
	EP_EOL,
	EP_INPUT,
	EP_OTHER,
	EP_PIPE,
	EP_QUOTE_1,
	EP_QUOTE_2,
	EP_WHITESPACE,
	EP_WORD,
}	t_ep_token_type;

typedef enum e_ep_status
{
	EP_SUCCESS = 0,
	EP_ERR_MALLOC,
}	t_ep_status;

typedef struct s_ep_token
{
	t_ep_token_type		type;
	int					length;
	char				*data;
}	t_ep_token;	


typedef struct s_ep_result
{
	t_li_node	*tokens;
	t_ep_status	status;
}	t_ep_result;

t_ep_result	ep_expand(t_ks_kotistate *state, t_li_node *tokens);
void		ep_token_free(t_li_node *list);

#endif
