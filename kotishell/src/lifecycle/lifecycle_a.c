/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifecycle_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 16:18:32 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/10 20:10:38 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lifecycle.h"

t_ks_status	l_lc_init_kotistate(t_ks_kotistate *kotistate, char **envp)
{
	t_ks_kotivar	*path_var;
	int				i;
	int				eq_pos;

	i = 0;
	kotistate->env = NULL;
	while (envp[i])
	{
		path_var = mini_malloc(sizeof(t_ks_kotivar));
		eq_pos = mini_find(envp[i], '=');
		path_var->name = mini_substr(envp[i], eq_pos);
		path_var->value = mini_substr(envp[i] + eq_pos + 1, \
			mini_strlen(envp[i] + eq_pos + 1));
		li_new_stack(&(kotistate->env), path_var);
		++i;
	}
	kotistate->status_code = 0;
	return (KS_SUCCESS);
}

void	l_lc_clear_kotistate(t_ks_kotistate *kotistate)
{
	t_ks_kotivar	*var;
	t_li_node		*node;

	while (kotistate->env)
	{
		node = kotistate->env;
		kotistate->env = kotistate->env->next;
		var = node->data;
		free(var->name);
		free(var->value);
		free(var);
		free(node);
	}
}

void	lc_start_shell(int argc, char **argv, char **envp)
{
	char			*line;
	t_ks_kotistate	kotistate;

	(void) argc;
	(void) argv;
	l_lc_init_kotistate(&kotistate, envp);
	while (1)
	{
		line = readline("kotishell: ");
		if (!line)
		{
			rl_clear_history();
			l_lc_clear_kotistate(&kotistate);
			exit(EXIT_SUCCESS);
		}
		l_lc_process_line(line, &kotistate);
		add_history(line);
		free(line);
	}
}
