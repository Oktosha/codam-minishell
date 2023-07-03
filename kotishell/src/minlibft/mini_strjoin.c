/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_strjoin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 13:50:35 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/03 14:30:03 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*mini_strjoin(char *s1, char *s2, int len)
{
	char	*res;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		exit (EXIT_FAILURE);
	res = mini_malloc(sizeof(char) * (mini_strlen(s1) + len));
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' || j < len)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}
