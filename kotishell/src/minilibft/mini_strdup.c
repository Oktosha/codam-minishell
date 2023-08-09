/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_strdup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 19:51:27 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/07/31 21:54:36 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*mini_strdup(const char *s)
{
	int		len;
	int		i;
	char	*copy;

	len = mini_strlen(s);
	copy = mini_malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		copy[i] = s[i];
		i += 1;
	}
	return (copy);
}
