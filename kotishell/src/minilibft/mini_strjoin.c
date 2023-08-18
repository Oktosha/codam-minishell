/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_strjoin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 11:37:03 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/18 16:29:21 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*mini_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	mini_assert(s1 != NULL && s2 != NULL, "both strings not null");
	res = mini_malloc(sizeof(char) * (mini_strlen(s1) + mini_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
