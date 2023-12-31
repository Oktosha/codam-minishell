/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kotistate.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 15:52:34 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/01 13:49:57 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that expands variables after tokenizing.
 * Namespace prefix: "ks".
*/
#ifndef KOTISTATE_H
# define KOTISTATE_H
# include "lists.h"

typedef enum s_ks_status
{
	KS_SUCCESS,
	KS_ERR_INIT,
	KS_ERR_MALLOC,
	KS_ERR_SYNTAX,
	KS_ERR_SYMBOL,
}	t_ks_status;

typedef struct s_ks_kotivar
{
	char	*name;
	char	*value;
}	t_ks_kotivar;

typedef struct s_ks_kotistate
{
	int			status_code;
	t_li_node	*env;
}	t_ks_kotistate;

#endif
