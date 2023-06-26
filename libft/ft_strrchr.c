/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 16:28:03 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/04 12:18:24 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (str[i] == (char )c)
		{
			return (&str[i]);
		}
		i--;
	}
	return (0);
}

// int main(void)
// {
// 	char str[] = "whatever";
// 	printf("My result: %s", ft_strrchr(str, 'o'));
// 	printf("%s", "\n");
// 	printf("Real result: %s", strrchr(str, 'o'));
// 	return(0);
// }
