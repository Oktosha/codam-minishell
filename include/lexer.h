/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbp14 <mbp14@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:15:07 by mbp14         #+#    #+#                 */
/*   Updated: 2023/06/26 15:42:22 by mbp14         ########   odam.nl         */
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
	word,
	operator,
	variable,
	command,
}	t_token;


typedef enum s_state
{
	whitespace,
	quote,
	normal,
}	t_state;

void	start_shell(void);

#endif