/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifecycle_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 16:18:32 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 18:10:51 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "lifecycle.h"

t_ks_status	l_lc_init_kotistate(t_ks_kotistate *kotistate, char **envp)
{
	(void) envp;
	kotistate->status_code = 0;
	kotistate->cur_directory = getcwd(NULL, 0);
	if (kotistate->cur_directory == NULL)
		return (KS_ERR_INIT);
	kotistate->env = NULL;
	return (KS_SUCCESS);
}

void l_lc_clear_kotistate(t_ks_kotistate *kotistate)
{
	free(kotistate->cur_directory);
	kotistate->cur_directory = NULL;
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
