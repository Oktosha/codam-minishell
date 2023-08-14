/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_substr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 15:46:21 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/31 15:50:14 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*mini_substr(char *src, int len)
{
	char		*cmd;
	int			i;

	i = 0;
	cmd = mini_malloc(sizeof(char) * len + 1);
	if (!cmd)
		return (NULL);
	while (i < len)
	{
		cmd[i] = src[i];
		i++;
	}
	cmd[i] = '\0';
	return (cmd);
}
