/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_malloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:43:54 by evoronin      #+#    #+#                 */
/*   Updated: 2023/06/30 16:16:28 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*mini_malloc(size_t size)
{
	void	*ptr;

	if (size == 0)
	{
		mini_putstr_fd("BUG", 2);
		exit(EXIT_FAILURE);
	}
	ptr = malloc(size);
	return (ptr);
}
