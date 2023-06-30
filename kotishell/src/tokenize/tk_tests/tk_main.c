/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 18:55:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/06/30 18:57:37 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	main(void)
{
	tk_tokenize("what is this thing");
	printf('\n');
	tk_tokenize("what");
	printf('\n');
	tk_tokenize("");
	printf('\n');
	tk_tokenize("\t\t\t\t\t asfa tt    ");
	printf('\n');
	return (0);
}