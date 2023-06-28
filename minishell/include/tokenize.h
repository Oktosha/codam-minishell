/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 20:00:53 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/06/28 20:57:25 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that transforms string into tokens (aka lexer).
 * Namespace prefix: "tk".
*/
#ifndef TOKENIZE_H
# define TOKENIZE_H

typedef enum e_token
{
	TK_WORD,
	TK_PIPE,
	TK_HEREDOC,
	TK_NEWLINE,
	TK_LESS,
	TK_DGREAT,
	TK_GREAT,
}	t_token;

typedef enum s_state
{
	whitespace,
	quote,
	normal,
}	t_state;

#endif
