/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:36:52 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/17 12:49:52 by codespace     ########   odam.nl         */
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

int			li_list_size(t_li_node *list);
t_li_node	*li_new_list(void *data);
int			li_new_stack(t_li_node *list, void *data);
void		li_add_back(t_li_node **list, t_li_node *node);

#endif
