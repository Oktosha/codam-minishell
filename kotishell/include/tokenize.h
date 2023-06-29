/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 20:00:53 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/06/29 18:03:32 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that transforms string into tokens (aka lexer).
 * Namespace prefix: "tk".
*/
#ifndef TOKENIZE_H
# define TOKENIZE_H

# include <stdlib.h>
# include "lists.h"

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
	t_tk_token_type	type;
	int				length;
	char			*data;
}	t_tk_token;	

typedef struct s_tk_so_far
{
	t_li_node	*head;
	t_tk_token	last;
	const char	*error;
}	t_tk_so_far;

typedef struct s_tk_result
{
	t_li_node	*tokens;
	const char	*error;
}	t_tk_result;	

t_tk_result	tk_tokenize(char *s);

#endif
