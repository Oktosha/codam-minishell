/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_putstr_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:21:11 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/14 12:06:38 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	mini_putstr_fd(char *s, int fd)
{
	return(write(fd, s, mini_strlen(s)));
}

