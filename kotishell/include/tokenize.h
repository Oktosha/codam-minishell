/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 20:00:53 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/11 19:37:19 by evoronin      ########   odam.nl         */
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
	TK_WORD,
	TK_PIPE,
	TK_HEREDOC,
	TK_NEWLINE,
	TK_LESS,
	TK_DGREAT,
	TK_GREAT,
	TK_EMPTY,
	TK_WHITESPACE,
	TK_EOL,
}	t_tk_token_type;

typedef enum e_tk_state
{
	TK_ST_WHITESPACE,
	TK_ST_WORD,
	TK_ST_START,
	TK_ST_END,
}	t_tk_state;

typedef enum e_tk_symbol_type
{
	TK_SY_WHITESPACE,
	TK_SY_LETTER,
	TK_SY_EOL,
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
t_tk_symbol_type	s_tk_get_symbol_type(char c);
void				s_tk_init_so_far(t_tk_so_far *so_far);
void				s_tk_word(t_tk_so_far *so_far, char *s);
t_tk_result			tk_result(char *s);
void				tk_token_copy( t_tk_so_far *so_far);
void				tk_token_result(t_tk_result *result, t_tk_so_far *so_far);
t_tk_state			tk_next_state(t_tk_state state, char *s);

#endif
