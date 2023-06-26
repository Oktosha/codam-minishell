/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbp14 <mbp14@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:24:33 by mbp14         #+#    #+#                 */
/*   Updated: 2023/06/25 14:52:26 by mbp14         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/// @brief start shell programm
/// @param argc number of arguments given to program
/// @param argv argument givent to program
/// @return shell running on loop
int	main(void)
{
	start_shell();
	return (EXIT_SUCCESS);
}
