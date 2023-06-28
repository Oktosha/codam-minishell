/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:09:33 by evoronin      #+#    #+#                 */
/*   Updated: 2023/05/07 14:40:49 by mbp14         ########   odam.nl         */
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

void	*protect(void *ptr)
{
	if (ptr == NULL)
		exit(errno);
	return (ptr);
}

char	*get_path(char **cmd, char **envp)
{
	char	**new_paths;
	char	*path;
	int		i;
	char	*cmd_path;

	if (ft_strrchr(cmd[0], '/') != NULL && access(cmd[0], X_OK) == 0)
		return (cmd[0]);
	i = 0;
	new_paths = protect(get_new_path(cmd, envp));
	while (new_paths[i] != NULL)
	{
		path = protect(ft_strjoin(new_paths[i], "/"));
		cmd_path = ft_strjoin(path, cmd[0]);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		i++;
	}
	ft_error(cmd[0], 127);
	return (NULL);
}

void	*first_child(char **argv, char **envp, int fd[])
{
	int		input;
	char	**cmd;

	cmd = split_cmd(argv[2], ' ');
	if (!cmd)
		ft_error(argv[2], 127);
	close(fd[0]);
	input = open(argv[1], O_RDONLY);
	if (input == -1)
		ft_error("file not found", errno);
	if (dup2(input, STDIN_FILENO) == -1)
		ft_error("dup2", errno);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("dup2", errno);
	close(fd[1]);
	close(input);
	if (execve(get_path(cmd, envp), cmd, envp) == -1)
		ft_error("execve child 1", errno);
	return (NULL);
}

void	*second_child(char **argv, char **envp, int fd[])
{
	int		output;
	char	**cmd;

	cmd = split_cmd(argv[3], ' ');
	if (!cmd)
		ft_error(argv[3], 127);
	output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output == -1)
		ft_error("file not found", errno);
	if (dup2(output, STDOUT_FILENO) == -1)
		ft_error("dup2", errno);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("dup2", errno);
	close(fd[1]);
	close(fd[0]);
	close(output);
	if (execve(get_path(cmd, envp), cmd, envp) == -1)
		ft_error("execve child 2", errno);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	status;

	if (argc != 5)
		ft_error("Wrong number of args", errno);
	if (pipe(fd) == -1)
		ft_error("pipe", errno);
	pid1 = fork();
	if (pid1 == 0)
		first_child(argv, envp, fd);
	pid2 = fork();
	if (pid2 == 0)
		second_child(argv, envp, fd);
	if (pid1 == -1 || pid2 == -1)
		ft_error("fork1", errno);
	close(fd[0]);
	close(fd[1]);
	while (waitpid(-1, &status, 0) == -1)
	{
		if (WEXITSTATUS(status))
			exit(WEXITSTATUS(status));
	}
}
