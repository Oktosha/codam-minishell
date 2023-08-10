/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:48:11 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/10 19:13:53 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ex_execute(t_ks_kotistate *state, t_li_node *cmds)
{
	int				n_pipes;
	t_ex_plumbing	plumbing;
	int				retcode;

	if (li_list_size(cmds) == 0)
		return (state->status_code);
	if (li_list_size(cmds) == 1 \
		&& l_ex_is_builtin(((t_ps_single_command *)cmds->data)->argv->data))
		return (l_ex_builtin(state, cmds->data));
	n_pipes = li_list_size(cmds) - 1;
	plumbing = l_ex_create_plumbing(n_pipes);
	if (plumbing.fildesarr == NULL)
		return (88);
	l_ex_launch_all(state, cmds, plumbing);
	l_ex_full_plumbing_cleanup(&plumbing);
	retcode = l_ex_wait_all(cmds);
	return (retcode);
}
