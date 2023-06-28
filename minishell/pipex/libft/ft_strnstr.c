/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:33:05 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/17 17:08:12 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*src;
	char		*find;
	size_t		i;
	size_t		size;

	src = (char *)haystack;
	find = (char *)needle;
	i = 0;
	size = 0;
	if (find[size] == '\0')
		return (src);
	while (i < len && src[i] != '\0')
	{
		if (src[i + size] == find[size])
		{
			while (find[size] != '\0' && src[i + size] == find[size]
				&& (i + size) < len && src[i + size] != '\0')
					size++;
			if (size == (size_t)ft_strlen(find))
				return (&src[i]);
		}
		size = 0;
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("My result: %s", ft_strnstr("lorem ipsum sit amet", "ipsum", 27));
// 	printf("%s", "\n");
// 	printf("Real result: %s", strnstr("lorem ipsum sit amet", "ipsum", 27));
// 	return (0);
// }