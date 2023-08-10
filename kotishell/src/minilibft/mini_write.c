/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_write.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/10 16:48:35 by codespace     #+#    #+#                 */
/*   Updated: 2023/08/10 17:00:33 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	mini_write(int fd, const char *s, int length)
{
	if (write(fd, s, length) < length)
		exit(-10);
}
