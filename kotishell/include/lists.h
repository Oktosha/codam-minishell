/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 16:36:52 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/06/29 16:44:22 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that linked lists operations.
 * Namespace prefix: "li".
*/
#ifndef LISTS_H
# define LISTS_H

typedef struct s_li_node
{
	void		*data;
	t_li_node	*next;
}	t_li_node;

#endif
