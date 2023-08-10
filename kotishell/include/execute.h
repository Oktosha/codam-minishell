/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 19:59:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/09 16:24:49 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that takes commands and executes them.
 * Namespace prefix: "ex".
*/
#ifndef EXECUTE_H
# define EXECUTE_H
# include <sys/wait.h>
# include "kotistate.h"
# include "lists.h"
# include "lifecycle.h"
# include "minilibft.h"
# include "parse.h"

typedef int	t_ex_pipe[2];

typedef struct s_ex_plumbing {
	int			n_pipes;
	t_ex_pipe	*fildesarr;
}	t_ex_plumbing;

// a
int				ex_execute(t_ks_kotistate *state, t_li_node *cmds);

// b
void			*l_ex_free_array(char **array, int length);
char			**l_ex_one_value_string_array(char *s);
int				l_ex_n_records_before_null(char **array);
char			**l_ex_add_suffix_to_all(char **array, char *suf);
int				l_ex_count_char(char *s, char ch);

// c
char			*l_ex_extract_dir_by_len(char *s, int len);
char			*l_ex_extract_first_dir(char **sp);
char			*l_ex_extract_dir(char **sp);
char			**l_ex_extract_dir_candidates(char *s);
char			**l_ex_get_cmd_candidates(char *cmd, char *path_value);

// d
/**
 * @brief converts list of nodes to a null-terminated array
 * @warning doesn't allocate new strings!
*/
char			**l_ex_to_array(t_li_node *list);
char			*l_ex_get_path_value(t_li_node *env);
void			l_ex_fork(t_ks_kotistate *state, t_ps_single_command *cmd, \
	int cmd_index, t_ex_plumbing plumbing);
void			l_ex_launch_all(\
	t_ks_kotistate *state, t_li_node *cmds, t_ex_plumbing plumbing);
int				l_ex_wait_all(t_li_node *cmds);

// e
t_ex_plumbing	l_ex_create_plumbing(int n_pipes);
/**
 * @brief closes pipes that aren't used by cmd on position cmd_index
 * @note cmd_index starts with 1
*/
void			l_ex_close_usseless_pipes(\
	t_ex_plumbing plumbing, int cmd_index);
/**
 * @brief connects stdin and stdout to pipes appropriately for cmd_index
 * @note cmd_index starts with 1
*/
void			l_ex_connect_to_plumbing(\
	t_ex_plumbing plumbing, int cmd_index);
void			l_ex_full_plumbing_cleanup(t_ex_plumbing *plumbing);

// f
int				l_ex_builtin(t_ks_kotistate *state, t_ps_single_command *cmd);
char			*l_ex_kotivar_to_str(t_ks_kotivar *var);
char			**l_ex_env_to_array(t_li_node *env);
int				l_ex_is_builtin(char *name);
#endif
