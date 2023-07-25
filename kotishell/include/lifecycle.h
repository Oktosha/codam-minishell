/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifecycle.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:15:07 by mbp14         #+#    #+#                 */
/*   Updated: 2023/07/25 15:55:04 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that manages shell life.
 * Namespace prefix: "lc".
*/
#ifndef LIFECYCLE_H
# define LIFECYCLE_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/errno.h>
# include "execute.h"
# include "expand.h"
# include "kotistate.h"
# include "lex.h"
# include "lists.h"
# include "minilibft.h"
# include "parse.h"
# include "tokenize.h"

void	lc_start_shell(int argc, char **argv, char **envp);

#endif
