/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 15:32:44 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:36:25 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	char			*s2;
	size_t			i;
	size_t			size;

	s1 = (char *)s;
	size = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	if (len >= size)
		s2 = (char *)malloc((size + 1) * sizeof(char));
	else
		s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (len > 0 && s1 && start <= size)
	{
		s2[i] = s1[start];
		len--;
		start++;
		i++;
	}
	s2[i] = 0;
	return (s2);
}

// int main(void)
// {
// 	char str[] = "i just want this part #############";
// 	printf("My result: %s", ft_substr(str, 5, 10));
// 	return(0);
// }
