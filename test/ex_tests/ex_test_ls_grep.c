#include "execute.h"

void ex_test_ls_grep(void)
{
	t_li_node argv1;
	argv1.data = "ls";
	argv1.next = NULL;
	t_ps_single_command cmd1;
	cmd1.argv = &argv1;
	cmd1.inputs = NULL;
	cmd1.outputs = NULL;
	cmd1.pid = -1;
	t_li_node argv2_arg;
	argv2_arg.data = "e";
	argv2_arg.next = NULL;
	t_li_node argv2_name;
	argv2_name.data = "grep";
	argv2_name.next = &argv2_arg;
	t_ps_single_command cmd2;
	cmd2.argv = &argv2_name;
	cmd2.inputs = NULL;
	cmd2.outputs = NULL;
	cmd2.pid = -1;
	t_li_node cmd_node_2;
	cmd_node_2.data = &cmd2;
	cmd_node_2.next = NULL;
	t_li_node cmd_node_1;
	cmd_node_1.data = &cmd1;
	cmd_node_1.next = &cmd_node_2;
	t_ks_kotistate state;
	t_ks_kotivar var;
	var.name = "PATH";
	var.value = "/bin:/usr/bin";
	t_li_node env;
	env.next = NULL;
	env.data = &var;
	state.env = &env;
	state.status_code = -5;
	ex_execute(&state, &cmd_node_1);
}

int main()
{
	ex_test_ls_grep();
	return 0;
}
