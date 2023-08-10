/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_putstr_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:21:11 by evoronin      #+#    #+#                 */
/*   Updated: 2023/08/10 16:57:14 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	mini_putstr_fd(const char *s, int fd)
{
	mini_write(fd, s, mini_strlen(s));
}
