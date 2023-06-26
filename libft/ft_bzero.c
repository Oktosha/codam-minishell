/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:43:38 by evoronin      #+#    #+#                 */
/*   Updated: 2022/10/18 12:28:24 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		str[i] = '\0';
		n--;
		i++;
	}
}

// int main(void)
// {
// 	char  str[] = "whatever";
// 	ft_bzero(str, 5);
// 	printf("My function: %s", str);
// 	printf("%s", "\n");
// 	printf("bzero: %s", bzero(str, 5));
// 	printf("%s", "\n");
// 	return(0);
// }
