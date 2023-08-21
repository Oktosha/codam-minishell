/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:36:52 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/21 16:01:24 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that linked lists operations.
 * Namespace prefix: "li".
*/
#ifndef LISTS_H
# define LISTS_H

# include <stdlib.h>
# include <stdio.h>
# include "minilibft.h"

typedef struct s_li_node
{
	void				*data;
	struct s_li_node	*next;
}	t_li_node;

int			li_list_size(void *data);
t_li_node	*li_new_list(void *data);
int			li_new_stack(void **void_list, void *data);
void		li_add_back(t_li_node **list, t_li_node *node);

#endif
