/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:43:38 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:34:28 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;
	if (!len || str == str2)
		return (str);
	if (str < str2)
		ft_memcpy(str, str2, len);
	else
	{
		while (len > 0)
		{
			str[len -1] = str2[len -1];
			len--;
		}
	}
	return (str);
}

// int main(void)
// {
// 	char dest[50] = "123bcd";
// 	char source[50] ="abcd";
// 	printf("Before ft_memmove: %s", dest);
// 	printf("%s", "\n");
// 	printf("After ft_memmove: %s", ft_memmove(dest, source, 24));
// 	printf("%s", "\n");
// 	printf("Real memmove: %s",memmove(dest, source, 24));
// 	return(0);
// }
