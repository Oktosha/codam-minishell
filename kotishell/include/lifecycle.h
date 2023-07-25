/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifecycle.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:15:07 by mbp14         #+#    #+#                 */
/*   Updated: 2023/07/25 18:10:51 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that manages shell life.
 * Namespace prefix: "lc".
*/
#ifndef LIFECYCLE_H
# define LIFECYCLE_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/errno.h>
# include <unistd.h>
# include "execute.h"
# include "expand.h"
# include "kotistate.h"
# include "lex.h"
# include "lists.h"
# include "minilibft.h"
# include "parse.h"
# include "tokenize.h"

typedef struct s_lc_process_data
{
	t_tk_result	tk_result;
	t_lx_result	lx_result;
	t_ep_result	ep_result;
	t_ps_result	ps_result;
}	t_lc_process_data;

typedef enum s_lc_status
{
	LC_SUCCESS = 0,
	LC_ERROR
}	t_lc_status;

void		lc_start_shell(int argc, char **argv, char **envp);
t_ks_status	l_lc_init_kotistate(t_ks_kotistate *kotistate, char **envp);
void		l_lc_clear_kotistate(t_ks_kotistate *kotistate);
void		l_lc_process_data_cleanup(t_lc_process_data *data);
void		l_lc_init_process_data(t_lc_process_data *data);
void		l_lc_process_line(char *line, t_ks_kotistate *kotistate);
void		l_lc_handle_tokenize_status(t_tk_status tk_status, \
			t_ks_kotistate *kotistate, t_lc_status *lc_status);
void		l_lc_handle_lex_status(t_lx_status lx_status, \
			t_ks_kotistate *kotistate, t_lc_status *lc_status);	

#endif
