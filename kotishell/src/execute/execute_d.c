/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/01 13:53:24 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/08/02 16:17:10 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	**l_ex_to_array(t_li_node *list)
{
	int		len;
	int		i;
	char	**array;

	len = li_list_size(list);
	array = mini_malloc((len + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array[len] = NULL;
	i = 0;
	while(list)
	{
		array[i] = list->data;
		list = list->next;
		i += 1;
	}
	return (array);
}

char	*l_ex_get_path_value(t_li_node *env)
{
	t_ks_kotivar	*variable;
	while(env)
	{
		variable = env->data;
		if (mini_strcmp(variable->name, "PATH") == 0)
			return (variable->value);
	}
	return ("");
}

void	l_ex_fork(\
	t_ks_kotistate *state, t_ps_single_command *cmd, int fd_in, int fd_out)
{
	char	**cmd_candidates;
	char	**argv;
	char	**envp;
	int		i;

	cmd->pid = fork();
	if (cmd->pid <= 0)
		return ;
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	if (l_ex_is_builtin(cmd->argv->data))
		exit(l_ex_builtin(state, cmd));
	cmd_candidates = l_ex_get_cmd_candidates(cmd->argv->data, \
		l_ex_get_path_value(state->env));
	argv = l_ex_to_array(cmd->argv);
	envp = l_ex_env_to_array(state->env);
	if (!cmd_candidates || !argv || !envp)
		exit(88);
	i = 0;
	while (cmd_candidates[i] && execve(cmd_candidates[i], argv, envp))
		++i;
	printf("execve failed for some reason\n");
}

void	l_ex_launch_all(\
	t_ks_kotistate *state, t_li_node *cmds, t_ex_pipe_array pipes)
{
	int i;

	i = 0;
	while (cmds)
	{
		l_ex_fork(state, cmds->data, pipes[i - 1][0], pipes[i][1]);
		i += 1;
		cmds = cmds->next;
	}
}

int	l_ex_wait_all(t_li_node *cmds)
{
	t_ps_single_command *cmd;
	int					status;

	while(cmds)
	{
		cmd = cmds->data;
		if (cmd->pid > 0)
		{
			waitpid(cmd->pid, &status, 0);
		}
		cmds = cmds->next;
	}
	return (status);
}
