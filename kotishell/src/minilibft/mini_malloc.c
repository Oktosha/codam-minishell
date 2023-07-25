/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_malloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:43:54 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/21 15:30:40 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*mini_malloc(size_t size)
{
	void	*ptr;

	mini_assert(size > 0, "SIZE IN MALLOC GREATER THAN 0");
	ptr = malloc(size);
	return (ptr);
}
