/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:15:07 by mbp14         #+#    #+#                 */
/*   Updated: 2023/06/26 17:54:08 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/errno.h>

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

void	start_shell(void);

#endif
