/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_write.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/10 16:48:35 by codespace     #+#    #+#                 */
/*   Updated: 2023/08/10 16:49:59 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void    mini_write(int fd, char *s, int length)
{
    if (write(fd, s, length) < length)
        exit(-10);
}