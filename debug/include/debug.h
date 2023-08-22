/** @file 
 * Module that takes commands and executes them.
 * Namespace prefix: "ex".
*/
#ifndef DEBUG_H
# define DEBUG_H

# include "tokenize.h"
# include "lex.h"
# include "expand.h"
# include "parse.h"

typedef struct s_dbg_dummy_tk_token {
	t_tk_token_type	type;
	char			*data;
}	t_dbg_dummy_tk_token;

typedef struct s_dbg_dummy_lx_token {
	t_lx_token_type	type;
	char			*data;
}	t_dbg_dummy_lx_token;

typedef struct s_dbg_dummy_ep_token {
	t_lx_token_type	type;
	char			*data;
}	t_dbg_dummy_ep_token;

typedef struct s_dbg_dummy_ps_input {
	char			*name;
	t_ps_input_type	type;
}	t_dbg_dummy_ps_input;

typedef struct s_dbg_dummy_ps_output {
	char				*name;
	t_ps_output_type	type;
}	t_dbg_dummy_ps_output;

typedef struct s_dbg_dummy_ps_command {
	char					*argv[20];
	t_dbg_dummy_ps_input	inputs[7];
	t_dbg_dummy_ps_output	outputs[7];
}	t_dbg_dummy_ps_command;

typedef struct s_dbg_tk_token_sequence {
	t_li_node	*tokens;
	char		*s;
}	t_dbg_tk_token_sequence;

typedef struct s_dbg_lx_token_sequence {
	t_li_node *tokens;
	char *s;
}	t_dbg_lx_token_sequence;

t_dbg_tk_token_sequence	dbg_create_tk_token_sequence(t_dbg_dummy_tk_token *tk_token_dummies);
t_dbg_lx_token_sequence	dbg_create_lx_token_sequence(t_dbg_dummy_lx_token *lx_token_dummies);
t_li_node				*dbg_create_ep_token_list(t_dbg_dummy_ep_token *ep_token_dummies);
t_li_node				*dbg_create_ps_command_list(t_dbg_dummy_ps_command *ps_command_dummies);

void					dbg_clear_tk_token_sequence(t_dbg_tk_token_sequence *seq);
void					dbg_clear_lx_token_sequence(t_dbg_lx_token_sequence *seq);

int						dbg_are_tk_tokens_equal(t_tk_token *a, t_tk_token *b);
int						dbg_are_lx_tokens_equal(t_lx_token *a, t_lx_token *b);
int						dbg_are_ep_tokens_equal(t_ep_token *a, t_ep_token *b);
int						dbg_are_ps_commands_equal(t_ps_single_command *a, t_ps_single_command *b);

int						dbg_are_tk_token_lists_equal(t_li_node *a, t_li_node *b);
int						dbg_are_lx_token_lists_equal(t_li_node *a, t_li_node *b);
int						dbg_are_ep_token_lists_equal(t_li_node *a, t_li_node *b);
int						dbg_are_ps_command_lists_equal(t_li_node *a, t_li_node *b);

void					*dbg_failast_malloc(int size);

#endif
