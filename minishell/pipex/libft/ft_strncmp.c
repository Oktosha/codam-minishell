/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 16:02:25 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:37:46 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] != '\0' && str1[i] == str2[i] && i < n - 1)
	{
			i++;
	}
	return (str1[i] - str2[i]);
}

// int main(void)
// {
// 	char str1[] = "abcdefgh";
// 	char str2[] = "abcdwxyz";
// 	printf("My result: %d", ft_strncmp(str1, str2, 4));
// 	printf("Real result: %d", strncmp(str1, str2, 4));
// 	return(0);
// }
