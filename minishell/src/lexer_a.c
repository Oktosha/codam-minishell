/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 16:18:32 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/06/28 17:19:50 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


// char	**lexer(char **args, char *line)
// {
// 	int			i;
// 	int			j;
// 	t_state		state;
// 	int			

// 	i = 0;
// 	j = 0;
// 	state.whit
// 	while (line != '\0')
// 	{
// 		if 
// 	}
// 	return (args);
// }

void	start_shell(void)
{
	char	*line;
	char	**args;
	int		status;
	int i = 0;

	while (1)
	{
		line = readline("kotishell: ");
		if (!line)
			exit (EXIT_FAILURE);
		add_history(line);
		// args = malloc(sizeof(line));
		// if (!args)
		// {
		// 	free(line);
		// 	exit (EXIT_FAILURE);
		// }
		i = 0;
		while (line[i] != '\0')
		{
			printf("line: %d\n", line[i]);
			i++;
		}
		
		// args = lexer(args, line);
		// if (args[0] == exit)
		// {
		// 	free(line);
		// 	exit(errno);
		// }
	}
}
