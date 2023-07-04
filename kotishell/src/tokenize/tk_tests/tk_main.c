/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 18:55:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/04 17:40:31 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	main(void)
{
	tk_tokenize("what is this here ");
	printf("\n");
	tk_tokenize("what");
	printf("\n");
	tk_tokenize("");
	printf("\n");
	tk_tokenize("\t\t\t\t\t asfa tt    ");
	printf("\n");
	return (0);
}
