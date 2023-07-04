/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_substr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 13:30:03 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/04 18:13:46 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*mini_substr(char *s1, unsigned int start, size_t len)
{
	char			*s2;
	size_t			i;
	size_t			size;

	size = mini_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	if (len >= size)
		s2 = mini_malloc((size + 1) * sizeof(char));
	else
		s2 = mini_malloc((len + 1) * sizeof(char));
	i = 0;
	while (len > 0 && s1 && start <= size)
	{
		s2[i] = s1[start];
		len--;
		start++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
