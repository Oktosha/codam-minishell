/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 16:28:03 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/04 12:16:17 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i] != (char) c && str[i])
	{
		i++;
	}
	if (str[i] == (char) c)
		return (&str[i]);
	return (NULL);
}

// int main(void)
// {
// 	char str[] = "tçeste";
// 	printf("My result: %p", ft_strchr(str, 231));
// 	printf("%s", "\n");
// 	printf("Real result: %p", strchr(str, 231));
// 	return(0);
// }
