/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifecycle_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 16:18:32 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/18 14:00:35 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lifecycle.h"

/** @brief start shell programm
 * @param argc number of arguments given to program
 * @param argv argument givent to program
 * @param envp enviroment variable
 * @return shell running on loop
*/
void	lc_start_shell(int argc, char **argv, char **envp)
{
	char	*line;
	int		i;

	i = 0;
	if (argc == 0)
		exit(EXIT_FAILURE);
	argv = NULL;
	envp = NULL;
	while (1)
	{
		line = readline("kotishell: ");
		if (!line)
			exit (EXIT_FAILURE);
		add_history(line);
		i = 0;
	}
}
