/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_strlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:33:22 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/21 15:35:46 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int	mini_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
