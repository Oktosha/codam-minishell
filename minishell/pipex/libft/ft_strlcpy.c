/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 14:18:46 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:35:13 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1) && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	s1[6] = "rrrrrr";
// 	char	s2[] = "lorem ipsum dolor sit amet";

// 	ft_strlcpy(s1, s2, 0);
// 	printf("My result: %zu", ft_strlcpy(s1, s2, 0));
// 	printf("%s", "\n");
// 	printf("%s",  s1);
// 	printf("%s", "\n");
// 	printf("Real result: %lu", strlcpy(s1, s2, 0));
// 	printf("%s", "\n");
// 	printf("%s",  s1);
// 	return(0);
// }
