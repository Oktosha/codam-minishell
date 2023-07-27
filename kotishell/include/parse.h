/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 15:06:03 by mbp14         #+#    #+#                 */
/*   Updated: 2023/07/27 14:02:09 by evoronin      ########   odam.nl         */
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
	t_li_node		*argv;
	t_li_node		*inputs;
	t_li_node		*outputs;
	t_li_node		*appends;
	t_li_node		*heredoc;
}	t_ps_single_command;

/**
 * Included in PS_ERR_SYNTAX:
 * ||, |||, <<<, >>>, <<|, >>| (with and without whitespaces)
*/
typedef enum s_ps_status
{
	PS_SUCCESS,
	PS_ERR_MALLOC,
	PS_ERR_SYNTAX,
}	t_ps_status;

typedef struct s_ps_result
{
	t_li_node	*cmds;
	t_ps_status	status;
}	t_ps_result;

t_ps_result	ps_parse(t_li_node *tokens);
void		ps_cmds_free(t_li_node *list);

#endif
