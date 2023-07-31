/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 21:58:38 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/07/31 22:18:15 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	*l_ex_free_array(char **array, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		mini_free(array[i]);
		i += 1;
	}
	mini_free(array);
	return (NULL);
}

char	**l_ex_one_value_string_array(char *s)
{
	char	**array;

	array = mini_malloc(2 * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array[1] = NULL;
	array[0] = mini_strdup(s);
	if (array[0] == NULL)
		return (mini_free(array));
	return (array);
}

int	l_ex_n_records_before_null(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		++i;
	return (i);
}

char	**l_ex_add_suffix_to_all(char **array, char *suf)
{
	char	**answer;
	int		len;
	int		i;

	len = l_ex_n_records_before_null(array);
	answer = mini_malloc(len * (sizeof(char *) + 1));
	if (answer == NULL)
		return (NULL);
	answer[len] = NULL;
	i = 0;
	while (i < len)
	{
		answer[i] = mini_concat(array[i], suf);
		if (answer[i] == NULL)
			return (l_ex_free_array(answer, i));
		++i;
	}
	return (answer);
}

int	l_ex_count_char(char *s, char ch)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == ch)
			cnt += 1;
		i += 1;
	}
	return (cnt);
}
