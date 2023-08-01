/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:48:11 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/01 18:11:09 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ex_execute(t_ks_kotistate *state, t_li_node *cmds)
{
	t_ps_single_command	*s_cmd;

	(void) state;
	(void) cmds;
	s_cmd = cmds->data;
	printf("I AM EXECUTING: %s\n", (char *)s_cmd->argv->data);
}
