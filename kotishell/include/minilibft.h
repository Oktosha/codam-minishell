/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minilibft.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:23:07 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/03 14:30:14 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

void		mini_putstr_fd(char *s, int fd);
void		*mini_malloc(size_t size);
int			mini_strlen(char *s);
char		*mini_substr(char *s1, unsigned int start, size_t len);
char		*mini_strjoin(char *s1, char *s2, int len);

#endif