/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 17:37:05 by evoronin      #+#    #+#                 */
/*   Updated: 2023/06/21 14:42:10 by mbp14         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_error(char *str, int error)
{
	errno = error;
	ft_putstr_fd("pipex error: ", 2);
	if (errno == 127)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else
	{
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
	exit(errno);
}

// free memory for split_cmd
void	ft_free(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free (arr);
}

int	check_length(const char *s, int i)
{
	int	len;

	len = 1;
	i++;
	while (s[i])
	{
		len++;
		i++;
	}
	if (s[i] == 39 || s[i] == 34)
		len++;
	return (len);
}

char	**get_new_path(char **cmd, char **envp)
{
	char	**new_paths;
	char	*path;
	int		i;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	path = NULL;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		ft_error(cmd[0], 127);
	new_paths = protect(ft_split(envp[i] + 5, ':'));
	return (new_paths);
}
