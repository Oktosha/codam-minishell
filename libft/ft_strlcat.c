/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 14:18:46 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:35:07 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	count;
	size_t	res;

	i = ft_strlen(dest);
	count = ft_strlen(src);
	if (size > i)
		res = i + count;
	else
		res = size + count;
	count = 0;
	while (src[count] && i + 1 < size)
	{
		dest[i] = src[count];
		count++;
		i++;
	}
	dest[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char dest[15] = "a";
// 	char src[26] = "lorem ipsum dolor sit amet";
// 	// printf("My result: %lu", ft_strlcat(dest, src, 15));
// 	// printf("%s", "\n");
// 	// printf("%s", dest);
// 	// printf("%s", "\n");
// 	printf("Real result: %lu", strlcat(dest, src, 15));
// 	printf("%s", "\n");
// 	printf("%s", dest);
// 	printf("%s", "\n");
// 	return(0);
// }
