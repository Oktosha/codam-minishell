/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 16:18:45 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/06/28 17:19:39 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief start shell programm
/// @param argc number of arguments given to program
/// @param argv argument givent to program
/// @return shell running on loop
int	main(void)
{
	start_shell();
	return (EXIT_SUCCESS);
}
