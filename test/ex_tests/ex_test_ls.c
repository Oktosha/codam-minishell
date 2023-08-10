#include "execute.h"

void ex_test_ls(void)
{
	t_li_node argv;
	argv.data = "ls";
	argv.next = NULL;
	t_ps_single_command cmd;
	cmd.argv = &argv;
	cmd.inputs = NULL;
	cmd.outputs = NULL;
	cmd.pid = -1;
	t_li_node cmds;
	cmds.data = &cmd;
	cmds.next = NULL;
	t_ks_kotistate state;
	t_ks_kotivar var;
	var.name = "PATH";
	var.value = "/bin";
	t_li_node env;
	env.next = NULL;
	env.data = &var;
	state.env = &env;
	state.status_code = -5;
	ex_execute(&state, &cmds);
}

int main()
{
	ex_test_ls();
	return 0;
}
