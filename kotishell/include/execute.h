/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 19:59:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/02 15:02:00 by dkolodze      ########   odam.nl         */
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
# include "parse.h"

typedef int(*t_ex_pipe_array)[2];

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
void			l_ex_fork(\
	t_ks_kotistate *state, t_ps_single_command *cmd, int fd_in, int fd_out);
void			l_ex_launch_all(\
	t_ks_kotistate *state, t_li_node *cmds, t_ex_pipe_array pipes);
int				l_ex_wait_all(t_li_node *cmds);

// e
t_ex_pipe_array	l_ex_create_pipes(int n_pipes);
void			*l_ex_cleanup_pipes(int n_pipes, t_ex_pipe_array *pipes);
char			*l_ex_kotivar_to_str(t_ks_kotivar *var);
char			**l_ex_env_to_array(t_li_node *env);
int				l_ex_is_builtin(char *name);

// f
int				l_ex_builtin(t_ks_kotistate *state, t_ps_single_command *cmd);			
#endif
