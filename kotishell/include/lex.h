/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 19:05:28 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 14:39:30 by elenavoroni   ########   odam.nl         */
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
# include "tokenize.h"

typedef enum e_lx_token_type
{
	LX_BAD,
	// TK_DOLLAR,
	LX_HEREDOC,
	LX_APPEND,
	LX_OUTPUT,
	LX_EMPTY,
	// LX_EOL,
	LX_INPUT,
	// LX_NEWLINE,
	LX_OTHER,
	LX_PIPE,
	LX_QUOTE_1,
	LX_QUOTE_2,
	// TK_QUESTION,
	LX_VARIABLE,
	LX_WHITESPACE,
	LX_WORD,
}	t_lx_token_type;

// typedef


#endif
