/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 15:06:03 by mbp14         #+#    #+#                 */
/*   Updated: 2023/07/25 14:23:50 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that transforms tokens into commands.
 * Variables should be expanded in the previous step.
 * Namespace prefix: "ps".
*/
#ifndef PARSE_H
# define PARSE_H
# include "lists.h"

typedef struct s_ps_single_command
{
	char			**argv;
	t_li_node		*inputs;
	t_li_node		*outputs;
	t_li_node		*appends;
	t_li_node		*heredoc;
}	t_ps_single_command;

typedef struct s_ps_command_list
{
	t_li_node	*cmds;
	char		*heredoc;
	int			heredoc_nr;
}	t_ps_command_list;

#endif
