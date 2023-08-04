/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_concat.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 20:13:19 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/07/31 20:17:40 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*mini_concat(const char *s1, const char *s2)
{
	char	*s;
	int		i;
	int		len1;
	int		len2;

	len1 = mini_strlen(s1);
	len2 = mini_strlen(s2);
	s = mini_malloc((len1 + len2 + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[len1 + len2] = '\0';
	i = 0;
	while (i < len1)
	{
		s[i] = s1[i];
		i += 1;
	}
	while (i < (len1 + len2))
	{
		s[i] = s2[i - len1];
		i += 1;
	}
	return (s);
}
