/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 19:05:28 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/27 13:43:09 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that takes small tokens and groups them.
 * Result is tokens with variables for expansion.
 * Group << and >> .
 * Group pipes.
 * Namespace prefix: "lx".
*/
#ifndef LEX_H
# define LEX_H
# include "lists.h"
# include "minilibft.h"
# include "tokenize.h"

typedef enum e_lx_token_type
{
	LX_BAD,
	LX_HEREDOC,
	LX_APPEND,
	LX_OUTPUT,
	LX_EMPTY,
	LX_INPUT,
	LX_OTHER,
	LX_PIPE,
	LX_QUOTE_1,
	LX_QUOTE_2,
	LX_VARIABLE,
	LX_WHITESPACE,
	LX_WORD,
}	t_lx_token_type;

typedef enum e_lx_state
{
	LX_ST_BUG,
	LX_ST_ERROR,
	LX_ST_HEREDOC,
	LX_ST_IMPORTANT,
	LX_ST_OTHER,
	LX_ST_QUOTE_1,
	LX_ST_QUOTE_2,
	LX_ST_START,
	LX_ST_VARIABLE,
	LX_ST_WORD,
}	t_lx_state;

/**
 * Included in LX_ERR_SYNTAX:
 * unclosed quote, 
 * newline before EOL
*/
typedef enum e_lx_status
{
	LX_SUCCESS = 0,
	LX_ERR_MALLOC,
	LX_ERR_SYNTAX, 
}	t_lx_status;

typedef struct s_lx_token
{
	t_lx_token_type		type;
	int					length;
	char				*data;
}	t_lx_token;	

typedef struct s_lx_so_far
{
	t_li_node	*head;
	t_lx_token	token;
	t_lx_status	status;
	t_lx_state	state;
}	t_lx_so_far;

typedef struct s_lx_result
{
	t_li_node	*tokens;
	t_lx_status	status;
}	t_lx_result;

t_lx_result	lx_lex(t_li_node *tk_tk);
void		lx_token_free(t_li_node *list);
void		l_lx_start(t_lx_so_far *so_far, t_li_node *tk_tk);
void		l_lx_init_so_far(t_lx_so_far *so_far);
void		l_lx_token_copy(t_lx_so_far *so_far);
void		l_lx_quotes_2(t_lx_so_far *so_far, t_tk_result *tk_res);
void		l_lx_token_result(t_lx_result *result, t_lx_so_far *so_far);
void		LX_print_list_test(t_li_node *list);
void		l_lx_err_unclosed_quote(t_lx_so_far *so_far);

#endif
