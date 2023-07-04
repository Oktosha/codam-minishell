/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_strlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:33:22 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/04 18:14:55 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	mini_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
