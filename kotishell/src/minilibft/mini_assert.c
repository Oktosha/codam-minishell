/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_assert.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 15:24:10 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/21 15:38:47 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	mini_assert(int condition, const char *str)
{
	if (condition == 0)
	{
		mini_putstr_fd("\033[0;31m\x1B[1mBUG! ASSERTION FAILED: \033[0m\x1B[1m", 2);
		mini_putstr_fd(str, 2);
		mini_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
}
