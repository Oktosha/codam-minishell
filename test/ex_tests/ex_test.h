#ifndef EX_TEST_H
# define EX_TEST_H

# include "execute.h"

# define EX_TEST_DUMMY_CMD_ARR_LEN 10

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

typedef struct s_EX_dummy_command {
	char		*argc[EX_TEST_DUMMY_CMD_ARR_LEN];
	t_ps_input	inputs[EX_TEST_DUMMY_CMD_ARR_LEN];
	t_ps_output	outputs[EX_TEST_DUMMY_CMD_ARR_LEN];
} t_EX_dummy_command;

#endif
