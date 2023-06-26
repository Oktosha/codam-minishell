/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 11:35:12 by evoronin      #+#    #+#                 */
/*   Updated: 2022/10/22 14:06:14 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char	tester(unsigned int i, char c)
// {

// 	printf("I am printing this:, %d, %c", i, c);
// 	printf("\n");
// 	return(0);
// }

// int main(void)
// {
// 	char str[] = "anything";
// 	unsigned int i = 10;
// 	ft_strmapi(str, tester);
// 	return (0);
// }
