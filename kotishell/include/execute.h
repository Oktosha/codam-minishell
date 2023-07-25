/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 19:59:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 15:55:16 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that takes commands and executes them.
 * Namespace prefix: "ex".
*/
#ifndef EXECUTE_H
# define EXECUTE_H
# include "kotistate.h"
# include "lists.h"
# include "lifecycle.h"

void	ex_execute(t_ks_kotistate *state, t_li_node *cmds);

#endif
