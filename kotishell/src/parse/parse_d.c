/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_d.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/10 13:24:42 by codespace     #+#    #+#                 */
/*   Updated: 2023/08/10 17:12:06 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ps_cmd_input_free(t_li_node *list)
{
	mini_assert(list == NULL, "No inputs\n");
}

void	ps_cmd_output_free(t_li_node *list)
{
	mini_assert(list == NULL, "No outputs\n");
}

void	ps_cmd_argv_free(t_li_node *list)
{
	t_li_node	*temp;

	while (list)
	{
		temp = list;
		free(temp->data);
		list = list->next;
		free(temp);
	}
}

void	ps_free_single_cmd(t_ps_single_command *cmd)
{
	ps_cmd_argv_free(cmd->argv);
	ps_cmd_input_free(cmd->inputs);
	ps_cmd_output_free(cmd->outputs);
	free(cmd);
}

void	ps_free_all_cmds(t_li_node *list)
{
	t_li_node	*temp;

	while (list)
	{
		temp = list;
		ps_free_single_cmd(temp->data);
		list = list->next;
		free(temp);
	}
}
