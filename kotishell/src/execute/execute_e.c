/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_e.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/01 17:17:21 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/08/09 16:21:46 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	l_ex_full_plumbing_cleanup(t_ex_plumbing *plumbing)
{
	int	i;

	i = 1;
	while (i <= plumbing->n_pipes)
	{
		close(plumbing->fildesarr[i][1]);
		close(plumbing->fildesarr[i][0]);
		i += 1;
	}
	free(plumbing->fildesarr);
	plumbing->fildesarr = NULL;
	plumbing->n_pipes = 0;
}

t_ex_plumbing	l_ex_create_plumbing(int n_pipes)
{
	t_ex_plumbing	plumbing;

	mini_assert(n_pipes >= 0, "requested number of pipes is non-negative");
	plumbing.n_pipes = 0;
	plumbing.fildesarr = mini_malloc((n_pipes + 2) * sizeof(t_ex_pipe));
	if (plumbing.fildesarr == NULL)
	{
		printf("TODO: malloc error creating pipes array\n");
		return (plumbing);
	}
	plumbing.fildesarr[0][0] = STDIN_FILENO;
	plumbing.fildesarr[n_pipes + 1][1] = STDOUT_FILENO;
	while (plumbing.n_pipes < n_pipes)
	{
		if (pipe(plumbing.fildesarr[plumbing.n_pipes + 1]) == -1)
		{
			printf("TODO: pipe error creating pipe %d\n", plumbing.n_pipes);
			l_ex_full_plumbing_cleanup(&plumbing);
			return (plumbing);
		}
		plumbing.n_pipes += 1;
	}
	return (plumbing);
}

void	l_ex_close_usseless_pipes(t_ex_plumbing plumbing, int cmd_index)
{
	int	cmd_input_index;
	int	cmd_output_index;
	int	i;

	mini_assert(cmd_index >= 1, "command index starts with 1");
	cmd_input_index = cmd_index - 1;
	cmd_output_index = cmd_index;
	i = 1;
	while (i <= plumbing.n_pipes)
	{
		if (i != cmd_input_index)
			close(plumbing.fildesarr[i][0]);
		if (i != cmd_output_index)
			close(plumbing.fildesarr[i][1]);
		i += 1;
	}
}

void	l_ex_connect_to_plumbing(t_ex_plumbing plumbing, int cmd_index)
{
	int	retcode;

	mini_assert(cmd_index >= 1, "cmd_index starts with 1");
	mini_assert(cmd_index <= plumbing.n_pipes + 1, "cmd_index fits plumbing");
	retcode = dup2(plumbing.fildesarr[cmd_index - 1][0], STDIN_FILENO);
	if (retcode == -1)
		mini_assert(0, "TODO: handle dup2 error\n");
	retcode = dup2(plumbing.fildesarr[cmd_index][1], STDOUT_FILENO);
	if (retcode == -1)
		mini_assert(0, "TODO: handle dup2 error\n");
}
