/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minilibft.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:23:07 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/14 12:06:46 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int 		mini_putstr_fd(char *s, int fd);
void		*mini_malloc(size_t size);
int			mini_strlen(char *s);

#endif
