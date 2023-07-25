/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minilibft.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:23:07 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/21 15:35:40 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int			mini_putstr_fd(const char *s, int fd);
void		*mini_malloc(size_t size);
int			mini_strlen(const char *s);
void		mini_assert(int condition, const char *str);

#endif
