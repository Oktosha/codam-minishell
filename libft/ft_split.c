/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 16:57:39 by evoronin      #+#    #+#                 */
/*   Updated: 2022/11/09 14:36:55 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

// free memory
static void	ft_free(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free (arr);
}

// count the length of the words
static int	ft_wordlen(const char *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	i++;
	return (len);
}

// count the number of words that will be in the array
static char	ft_countwords(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i + 1] != '\0'
				&& s[i] == c && s[i + 1] != c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	arr = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (j < ft_countwords(s, c))
	{
		while (s[i] == c)
			i++;
		arr[j] = ft_substr(s, i, ft_wordlen(s, c, i));
		if (!arr[j])
		{
			ft_free(arr, j);
			return (NULL);
		}
		i = i + ft_wordlen(s, c, i);
	j++;
	}
	arr[j] = 0;
	return (arr);
}

// int  main(void)
// {
// 	int i;
// 	char **split;
// 	i = 0;
// 	split = ft_split("  tripouille  42  ", ' ');
// 	while(split[i] != NULL)
// 	{
// 		printf("[%d]: %s\n", i, split[i]);
// 		i++;
// 	}
// 	return (0);
// }
