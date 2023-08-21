/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 19:57:44 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/21 14:11:48 by evoronin      ########   odam.nl         */
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
# include "minilibft.h"

typedef enum e_ep_token_type
{
	EP_BAD,
	EP_HEREDOC,
	EP_APPEND,
	EP_OUTPUT,
	EP_EMPTY,
	EP_INPUT,
	EP_PIPE,
	EP_QUOTE_1,
	EP_QUOTE_2,
	EP_WHITESPACE,
	EP_WORD,
}	t_ep_token_type;

typedef enum e_ep_state
{
	EP_ST_BUG,
	EP_ST_END,
	EP_ST_ERROR,
	EP_ST_HEREDOC,
	EP_ST_IMPORTANT,
	EP_ST_OTHER,
	EP_ST_QUOTE,
	EP_ST_PIPE,
	EP_ST_START,
	EP_ST_VARIABLE,
	EP_ST_WHITESPACE,
	EP_ST_WORD,
}	t_ep_state;

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

typedef struct s_ep_node_ep_token_ptr
{
	t_ep_token						*token;
	struct s_ep_node_ep_token_ptr	*next;
}	t_ep_node_ep_token_ptr;

typedef struct s_ep_so_far
{
	t_ep_node_ep_token_ptr	*head;
	t_ep_token				token;
	t_ep_status				status;
	t_ep_state				state;
}	t_ep_so_far;

typedef struct s_ep_result
{
	t_ep_node_ep_token_ptr	*tokens;
	t_ep_status				status;
}	t_ep_result;

t_ep_result			ep_expand(t_ks_kotistate *state, t_lx_node_lx_token_ptr *l);
void				ep_token_free(t_ep_node_ep_token_ptr *list);
void				l_ep_token_result(t_ep_result *result, t_ep_so_far *so_far);
void				l_ep_token_copy(t_ep_so_far *so_far);
void				l_ep_word(t_lx_node_lx_token_ptr *l, t_ep_so_far *so_far);
void				l_ep_start(t_lx_node_lx_token_ptr *l, t_ep_so_far *so_far);
void				l_ep_init_so_far(t_ep_so_far *so_far);
t_ep_state			l_ep_next_state(t_lx_token_type lx_tk);
void				l_ep_error_cleanup(t_lx_node_lx_token_ptr *l, t_ep_so_far *s);
void				l_ep_pipe(t_lx_node_lx_token_ptr *l, t_ep_so_far *so_far);
void				l_ep_whitespace(t_lx_node_lx_token_ptr *l, t_ep_so_far *s);

#endif
