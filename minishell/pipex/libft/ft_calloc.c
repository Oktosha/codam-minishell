/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:37:53 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/04 14:36:41 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	if (ptr == NULL)
		return (ptr);
	else
		ft_bzero(ptr, size * count);
	return (ptr);
}

// int main(void)
// {
// printf("My result: %p", ft_calloc(10, 8));
// printf("%s", "\n");
// printf("Real result: %p", calloc(10, 8));
// return(0);
// }
