/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:24:31 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:34:47 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && i < n - 1)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

// int main(void)
// {
// 	char str1[] = "\xff\xaa\xde\x12";
// 	char str2[] = "\xff\xaa\xde\x12MACOSAAAAA";
// 	printf("My result: %d", ft_memcmp(str1, str2, 4));
// 	printf("%s", "\n");
// 	printf("Real result: %d", memcmp(str1, str2, 4));
// 	return(0);
// }