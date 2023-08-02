/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_strcmp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 16:14:21 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/08/02 15:13:13 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	mini_strcmp(const char *a, const char *b)
{
	while (*a && *b)
	{
		if (*a > *b)
			return (1);
		if (*a < *b)
			return (-1);
		++a;
		++b;
	}
	if (*a > *b)
		return (1);
	if (*a < *b)
		return (-1);
	return (0);
}
