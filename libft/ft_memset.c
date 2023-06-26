/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:43:38 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:37:37 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = b;
	i = 0;
	while (len > 0)
	{
		str[i] = c;
		len--;
		i++;
	}
	return (b);
}

// int main(void)
// {
// 	char str[] = "whatever 1 2 3";
// 	unsigned char str1[] = "4";
// 	int i = 3;
// 	printf("My function: %s", ft_memset(str + 1, *str1, i));
// 	printf("%s", "\n");
// 	printf("Memset: %s", memset(str + 1, '4', 3));
// 	return(0);
// }
