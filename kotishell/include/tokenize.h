/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 20:00:53 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 17:30:23 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that transforms string into tokens (aka lexer).
 * Namespace prefix: "tk".
*/
#ifndef TOKENIZE_H
# define TOKENIZE_H

# include <stdio.h>
# include <stdlib.h>
# include "lists.h"
# include "minilibft.h"

typedef enum e_tk_token_type
{
	TK_BAD,
	TK_DOLLAR,
	TK_GREAT,
	TK_EMPTY,
	TK_EOL,
	TK_LESS,
	TK_NEWLINE,
	TK_OTHER,
	TK_PIPE,
	TK_QUOTE_1,
	TK_QUOTE_2,
	TK_QUESTION,
	TK_WHITESPACE,
	TK_WORD,
}	t_tk_token_type;

typedef enum e_tk_state
{
	TK_ST_BUG,
	TK_ST_END,
	TK_ST_ERROR,
	TK_ST_IMPORTANT,
	TK_ST_OTHER,
	TK_ST_START,
	TK_ST_WHITESPACE,
	TK_ST_WORD,
}	t_tk_state;

typedef enum e_tk_symbol_type
{
	TK_SY_ALPHANUM,
	TK_SY_BAD,
	TK_SY_EOL,
	TK_SY_IMPORTANT,
	TK_SY_NEWLINE,
	TK_SY_OTHER,
	TK_SY_WHITESPACE,
}	t_tk_symbol_type;

typedef struct s_tk_token
{
	t_tk_token_type		type;
	int					length;
	char				*data;
}	t_tk_token;	

typedef enum e_tk_status
{
	TK_SUCCESS = 0,
	TK_ERR_MALLOC,
	TK_ERR_SYMBOL,
}	t_tk_status;

typedef struct s_tk_so_far
{
	t_li_node	*head;
	t_tk_token	token;
	t_tk_status	status;
	t_tk_state	state;
}	t_tk_so_far;

typedef struct s_tk_result
{
	t_li_node	*tokens;
	t_tk_status	status;
}	t_tk_result;

t_tk_result			tk_tokenize(char *s);
t_tk_symbol_type	l_tk_get_symbol_type(char c);
void				l_tk_init_so_far(t_tk_so_far *so_far);
void				l_tk_word(t_tk_so_far *so_far, char *s);
t_tk_result			l_tk_result(char *s);
void				l_tk_token_copy( t_tk_so_far *so_far);
void				l_tk_token_result(t_tk_result *result, t_tk_so_far *so_far);
t_tk_state			l_tk_next_state(t_tk_state state, char *s);
void				tk_token_free(t_li_node *list);
void				l_tk_error_cleanup(t_tk_so_far *so_far);
void				l_tk_important(t_tk_so_far *so_far, char *s);
void				l_tk_end(t_tk_so_far *so_far, char *s);
void				l_tk_start_a(t_tk_so_far *so_far, char *s);
void				l_tk_start_b(t_tk_so_far *sf, char *s, t_tk_symbol_type sy);
void				l_tk_whitespace(t_tk_so_far *so_far, char *s);
t_tk_token_type		l_tk_get_token_type(char c);
t_tk_symbol_type	l_tk_get_symbol_whitespaces(char c);
void				l_tk_other(t_tk_so_far *so_far, char *s);
void				l_tk_symbol_error(t_tk_so_far *so_far);
void				l_tk_bad(t_tk_so_far *so_far, char *s);

#endif
