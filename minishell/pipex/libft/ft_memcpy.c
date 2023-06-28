/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:43:38 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:34:30 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;
	if (!n || str == str2)
		return (str);
	while (n > 0)
	{
		str[i] = str2[i];
		n--;
		i++;
	}
	return (str);
}

// int main(void)
// {
// 	char dest[1] = "";
// 	char source[1] ="";
// 	int i = 2;
// 	printf("Before ft_memcpy: %s", dest);
// 	ft_memcpy(dest, source, i);
// 	printf("%s", "\n");
// 	printf("After ft_memcpy: %s", dest);
// 	printf("%s", "\n");
// 	printf("Real memcpy: %s",memcpy(dest, source, i));
// 	return(0);
// }
