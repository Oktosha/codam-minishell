/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbp14 <mbp14@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:59:24 by mbp14         #+#    #+#                 */
/*   Updated: 2023/06/25 14:00:17 by mbp14         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"


char	**lexer(char **args, char *line)
{
	int			i;
	int			j;
	t_state		state;
	int			

	i = 0;
	j = 0;

	while (line != '\0')
	{

	}
	return (args);
}

void	start_shell(void)
{
	char	*line;
	char	**args;
	int		status;

	while (1)
	{
		line = readline("kotishell: ");
		if (!line)
			exit (EXIT_FAILURE);
		add_history(line);
		args = malloc(sizeof(line));
		if (!args)
		{
			free(line);
			exit (EXIT_FAILURE);
		}
		args = lexer(args, line);
		if (args[0] == exit)
		{
			free(line);
			exit(errno);
		}
	}
}
