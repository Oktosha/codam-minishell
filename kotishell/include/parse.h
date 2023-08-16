/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 15:06:03 by mbp14         #+#    #+#                 */
/*   Updated: 2023/08/16 14:21:55 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/** @file 
 * Module that transforms tokens into commands.
 * Variables should be expanded in the previous step.
 * Namespace prefix: "ps".
*/
#ifndef PARSE_H
# define PARSE_H
# include "expand.h"
# include "lists.h"
# include "minilibft.h"

typedef enum e_ps_token_type
{
	PS_BAD,
	PS_COMMAND,
	PS_HEREDOC,
	PS_APPEND,
	PS_OUTPUT,
	PS_EMPTY,
	PS_EOL,
	PS_INPUT,
}	t_ps_token_type;

typedef struct s_ps_input
{
	char	*name;
	int		type;	
	int		fd;
}	t_ps_input;

typedef struct s_ps_output
{
	char	*name;
	int		type;
	int		fd;
}	t_ps_output;

typedef struct s_ps_single_command
{
	t_li_node		*argv;
	t_li_node		*inputs;
	t_li_node		*outputs;
	int				pid;
}	t_ps_single_command;

/**
 * Included in PS_ERR_SYNTAX:
 * ||, |||, <<<, >>>, <<|, >>| (with and without whitespaces)
*/
typedef enum s_ps_status
{
	PS_SUCCESS,
	PS_ERR_MALLOC,
	PS_ERR_SYNTAX,
}	t_ps_status;

typedef enum e_ps_state
{
	PS_ST_BUG,
	PS_ST_COMMAND,
	PS_ST_END,
	PS_ST_ERROR,
	PS_ST_HEREDOC,
	PS_ST_INPUT,
	PS_ST_OUTPUT,
	PS_ST_QUOTE,
	PS_ST_PIPE,
	PS_ST_START,
	PS_ST_WHITESPACE,
}	t_ps_state;

typedef struct s_ps_so_far
{
	t_li_node			*head;
	t_ps_single_command	cmd;
	int					cmd_length;
	char				*cmd_data;
	t_ps_status			status;
	t_ps_state			state;
}	t_ps_so_far;

typedef struct s_ps_result
{
	t_li_node	*cmds;
	t_ps_status	status;
}	t_ps_result;

t_ps_result	ps_parse(t_li_node *tokens);
char		*mini_substr(char *src, int len);
void		l_ps_result(t_ps_result *result, t_ps_so_far *so_far);
void		l_ps_end(t_ps_so_far *so_far);
void		l_ps_error_cleanup(t_ps_so_far *so_far);
void		l_ps_syntax_error(t_ps_so_far *so_far);
t_ps_state	l_ps_next_state(t_ep_token_type ep_tk);
void		l_ps_input(t_li_node *ep_tk, t_ps_so_far *so_far);
void		l_ps_pipe(t_li_node *ep_tk, t_ps_so_far *so_far);
void		l_ps_init_so_far(t_ps_so_far *so_far);
void		l_ps_start(t_li_node *ep_tk, t_ps_so_far *so_far);
void		ps_free_all_cmds(t_li_node *list);
void		ps_free_single_cmd(t_ps_single_command *cmd);
void		ps_cmd_argv_free(t_li_node *list);
void		ps_cmd_output_free(t_li_node *list);
void		ps_cmd_input_free(t_li_node *list);
void		l_ps_reset_single_cmd(t_ps_single_command *cmd);

#endif
