/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_d.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/10 13:24:42 by codespace     #+#    #+#                 */
/*   Updated: 2023/08/21 20:27:13 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ps_cmd_input_free(t_ps_node_ps_input_ptr *list)
{
	mini_assert(list == NULL, "No inputs\n");
}

void	ps_cmd_output_free(t_ps_node_ps_output_ptr *list)
{
	mini_assert(list == NULL, "No outputs\n");
}

void	ps_cmd_argv_free(t_ps_node_char_ptr *list)
{
	char	*temp;

	while (list)
	{
		temp = list->argv;
		free(temp);
		list = list->next;
		free(temp);
	}
}

void	ps_free_single_cmd(t_ps_single_command *cmd)
{
	ps_cmd_argv_free(cmd->argvs);
	ps_cmd_input_free(cmd->inputs);
	ps_cmd_output_free(cmd->outputs);
	free(cmd);
}

void	ps_free_all_cmds(t_ps_node_ps_single_command_ptr *list)
{
	t_ps_node_ps_single_command_ptr	*temp;

	while (list)
	{
		temp = list;
		ps_free_single_cmd(temp->commands);
		list = list->next;
		free(temp);
	}
}
