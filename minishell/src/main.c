/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 16:18:45 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/06/28 20:17:01 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lifecycle.h"

int	main(int argc, char **argv, char **envp)
{
	lc_start_shell(argc, argv, envp);
	return (0);
}
