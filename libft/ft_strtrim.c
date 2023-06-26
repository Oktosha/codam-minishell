/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 09:54:47 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:36:42 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	first;
	size_t	last;

	first = 0;
	last = ft_strlen(s1);
	if (!s1 || !set)
		return (0);
	while (s1[first] && ft_strchr(set, s1[first]) != 0)
		first++;
	while (s1[last - 1] && ft_strrchr(set, s1[last]) != 0 && last > first)
		last--;
	res = (char *)malloc(sizeof(char) * (last - first + 2));
	if (!res)
		return (0);
	ft_strlcpy(res, &s1[first], last - first + 2);
	return (res);
}

	// int main(void)
	// {
	// 	char str1[] = "lorem ipsum dolor sit amet";
	// 		printf("My result: %s", ft_strtrim(str1, "te"));
	// 		return(0);
	// }
