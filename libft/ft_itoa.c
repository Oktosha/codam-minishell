/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 12:16:40 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/04 17:09:50 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static long int	ft_len(long int n)
{
	long int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_minint(long int nb)
{
	char		*res;
	int			i;

	i = ft_len(nb);
	if (nb == 0)
	{
		res = malloc(sizeof(char) * (i + 1));
		res[0] = 48;
		res[1] = '\0';
	}
	if (nb == -2147483648)
	{
		res = malloc(sizeof(char) * (12));
		res[0] = '-';
		res[1] = '2';
		res[i] = '\0';
		nb = 147483648;
	}
	while (nb > 0)
	{
		res[i - 1] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	long int	nb;

	nb = n;
	i = ft_len(nb);
	if (nb == 0 || nb == -2147483648)
		return (ft_minint(nb));
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		nb = n * -1;
	}
	while (nb > 0)
	{
		res[i - 1] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (res);
}

// int main(void)
// {
// 	printf("My result: %s", ft_itoa(-2147483648));
// 	return(0);
// }
