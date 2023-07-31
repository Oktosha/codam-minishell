/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 19:59:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/31 22:16:53 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that takes commands and executes them.
 * Namespace prefix: "ex".
*/
#ifndef EXECUTE_H
# define EXECUTE_H
# include "kotistate.h"
# include "lists.h"
# include "lifecycle.h"
# include "parse.h"

/**
 *  @defgroup ex_a execute module public functions
 *  These functions from execute_a.c are expected to be used from other modules
 *  @{
*/
void	ex_execute(t_ks_kotistate *state, t_li_node *cmds);
/** @} */ // end of group ex_a

/**
 *  @defgroup ex_b_arr execute module "private" functions for string arrays
 *  These functions from execute_b.c shouldn't be used from other modules
 *  @{
*/
void	*l_ex_free_array(char **array, int length);
char	**l_ex_one_value_string_array(char *s);
int		l_ex_n_records_before_null(char **array);
char	**l_ex_add_suffix_to_all(char **array, char *suf);
/** @} */ // end of group ex_b_arr

/**
 *  @defgroup ex_b_str execute module "private" function for strings
 *  This function from execute_b.c shouldn't be used from other modules
 *  @{
*/
int		l_ex_count_char(char *s, char ch);
/** @} */ // end of group ex_b_str

/**
 *  @defgroup ex_c execute module "private" functions for resolving path
 *  These functions from execute_c.c shouldn't be used from other modules
 *  @{
*/
char	*l_ex_extract_dir_by_len(char *s, int len);
char	*l_ex_extract_first_dir(char **sp);
char	*l_ex_extract_dir(char **sp);
char	**l_ex_extract_dir_candidates(char *s);
char	**l_ex_get_cmd_candidates(char *cmd, char *path_value);
/** @} */ // end of group ex_c

#endif
