/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:51:42 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:34:01 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char str[] = "whatever";
// 	printf("My result: %s", ft_memchr(str, '\0', 100));
// 	printf("%s", "\n");
// 	printf("Real result: %s", memchr(str, '\0', 100));
// 	return(0);
// }
