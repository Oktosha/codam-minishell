/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:22:02 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/02 14:01:07 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int		nbr;
	int		i;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
	{
		sign = sign * 1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

// int main(void)
// {
// 	char str[] = "0";
// 	printf("My result: %d", ft_atoi(str));
// 	printf("%s", "\n");
// 	printf("Real result: %d", atoi(str));
// 	return(0);
// }
