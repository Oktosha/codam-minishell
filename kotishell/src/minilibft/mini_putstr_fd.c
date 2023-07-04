/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_putstr_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:21:11 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/04 17:04:10 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	mini_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
