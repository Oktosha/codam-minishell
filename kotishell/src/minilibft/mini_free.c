/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_free.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 21:21:50 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/07/31 21:54:16 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*mini_free(void *p)
{
	free(p);
	return (NULL);
}
