/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_strlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:33:22 by evoronin      #+#    #+#                 */
/*   Updated: 2023/06/30 16:35:51 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	mini_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i++;
	return (i);
}