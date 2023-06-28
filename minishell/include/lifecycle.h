/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifecycle.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:15:07 by mbp14         #+#    #+#                 */
/*   Updated: 2023/06/28 20:10:21 by elenavoroni   ########   odam.nl         */
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

void	lc_start_shell(int argc, char **argv, char **envp);

#endif
