/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:12:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/05/07 14:40:27 by mbp14         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "libft/libft.h"

char			*get_path(char **cmd, char **envp);
void			ft_error(char *str, int error);
void			*first_child(char **argv, char **envp, int fd[]);
void			*second_child(char **argv, char **envp, int fd[]);
char			**split_cmd(char const *s, char c);
void			ft_free(char **arr, int j);
int				check_length(const char *s, int i);
char			**get_new_path(char **cmd, char **envp);
void	        *protect(void *ptr);

#endif