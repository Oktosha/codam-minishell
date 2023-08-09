/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_find.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 16:13:24 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/07/31 21:54:26 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	mini_find(char *s, char ch)
{
	int	i;

	i = 0;
	while (s[i] != ch && s[i])
	{
		i += 1;
	}
	if (s[i] == ch)
		return (i);
	return (-1);
}
