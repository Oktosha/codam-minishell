/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:16:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/21 20:42:03 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include "lex.h"
#include "lists.h"
#include "minilibft.h"
#include "tokenize.h"
#include "expand.h"
#include "parse.h"
#include <string.h>

void	PS_print_cmd(t_ps_single_command *cmd)
{
	t_ps_node_char_ptr	*argvs;

	argvs = cmd->argvs;
	while (argvs)
	{
		printf(" %s", (char *)argvs->argv);
		argvs = argvs->next;
	}
	printf("\n");
}

void	PS_print_cmds(t_ps_node_ps_single_command_ptr *cmds)
{
	int i;

	i = 0;
	while(cmds)
	{
		printf("[%d]", i);
		PS_print_cmd(cmds->commands);
		cmds = cmds->next;
		i += 1;
	}
}

int PS_are_equal(t_ps_single_command *expected, t_ps_single_command *real, int i)
{
	int expected_argv_len = li_list_size(expected->argvs);
	int	real_argv_len = li_list_size(real->argvs);
	if (expected_argv_len != real_argv_len)
	{
		printf("mismatch at cmd nr: %d\n", i);
		printf("expected argv length: %d\n", expected_argv_len);
		printf("real argv length: %d\n", real_argv_len);
		return 0;
	}
	t_ps_node_char_ptr *exp_argv_node = expected->argvs;
	t_ps_node_char_ptr *real_argv_node = real->argvs;
	for(int j = 0; j < real_argv_len; ++j)
	{
		char *exp_s = exp_argv_node->argv;
		char *real_s = real_argv_node->argv;
		if (strcmp(exp_s, real_s))
		{
			printf("mismatch at cmd nr: %d arg nr %d\n", i, j);
			printf("expected arg: %s\n", exp_s);
			printf("real arg: %s\n", real_s);
			return 0;
		}
		exp_argv_node = exp_argv_node->next;
		real_argv_node = real_argv_node->next;
	}
	return 1;
}

void	PS_test_parse(t_ep_result *ep_res, t_ps_node_ps_single_command_ptr *expected)
{
	t_ps_result 						res = ps_parse(ep_res->tokens);
	t_ps_node_ps_single_command_ptr 	*cur = res.cmds;
	int									len = li_list_size(expected);
	t_ps_node_ps_single_command_ptr		*cur_expected = expected;
	PS_print_cmds(res.cmds);
	int real_len = li_list_size(res.cmds);
	if (real_len != len)
	{
		printf("Wrong number of cmds: expcted=%d, real=%d\n", len, real_len);
		exit(1);
	}
	for (int i = 0; i < len; ++i)
	{
		t_ps_single_command *cur_cmd = cur->commands;
		t_ps_single_command *cur_expected_cmd = cur_expected->commands;
		if (!PS_are_equal(cur_expected_cmd, cur_cmd, i))
		{
			exit(1);
		}
		cur = cur->next;
		cur_expected = cur_expected->next;
	}
	ps_free_all_cmds(res.cmds);
	
	ep_token_free(ep_res->tokens);
}

t_ps_single_command	*create_cmd(char **argv)
{
	t_ps_single_command *cmd;
	cmd = mini_malloc(sizeof(t_ps_single_command));
	if (!cmd)
	{
		mini_putstr_fd("Cmd malloc bug\n", 2);
		exit(EXIT_FAILURE);
	}
	cmd->pid = -1;
	cmd->inputs = NULL;
	cmd->outputs = NULL;
	
	t_ps_node_char_ptr	*argv_node = NULL;
	int i = 0;
	while (argv[i] != NULL)
	{
		li_new_stack((void *)&argv_node, argv[i]);
		i++;
	}
	cmd->argvs = argv_node;
	return (cmd);
}

t_ps_node_ps_single_command_ptr *ps_create_expected_minishell(void)
{
	char *argv_mini[2] = {strdup("./minishell"), NULL};
	t_ps_single_command *cmd_mini = create_cmd(argv_mini);
	t_ps_node_ps_single_command_ptr *expected_cmds = NULL;
	li_new_stack((void *)&expected_cmds, cmd_mini);
	return expected_cmds;
}

t_ps_node_ps_single_command_ptr *ps_create_expected_echo_hi_bye(void)
{
	char *argv_echo_hi_bye[4] = {strdup("echo"), strdup("hi"), strdup("bye"), NULL};
	t_ps_single_command *cmd_echo_hi_bye = create_cmd(argv_echo_hi_bye);
	t_ps_node_ps_single_command_ptr *expected_cmds = NULL;
	li_new_stack((void *)&expected_cmds, cmd_echo_hi_bye);
	return expected_cmds;
}

t_ps_node_ps_single_command_ptr *ps_create_expected_ls_option(void)
{
	char *argv_ls_o[3] = {strdup("ls"), strdup("-la"), NULL};
	t_ps_single_command *cmd_ls_o = create_cmd(argv_ls_o);
	t_ps_node_ps_single_command_ptr *expected_cmds = NULL;
	li_new_stack((void *)&expected_cmds, cmd_ls_o);
	return expected_cmds;
}

t_ps_node_ps_single_command_ptr *ps_create_expected_bin_ls(void)
{
	char *argv_bin[2] = {strdup("/bin/ls"), NULL};
	t_ps_single_command *cmd_bin = create_cmd(argv_bin);
	t_ps_node_ps_single_command_ptr *expected_cmds = NULL;
	li_new_stack((void *)&expected_cmds, cmd_bin);
	return expected_cmds;
}

t_ps_node_ps_single_command_ptr *ps_create_expected_bin_wc(void)
{
	char *argv_bin[2] = {strdup("/bin/ls"), NULL};
	char *argv_wc[2] = {strdup("wc"), NULL};
	t_ps_single_command *cmd_bin = create_cmd(argv_bin);
	t_ps_single_command *cmd_wc = create_cmd(argv_wc);
	t_ps_node_ps_single_command_ptr *expected_cmds = NULL;
	li_new_stack((void *)&expected_cmds, cmd_bin);
	li_new_stack((void *)&expected_cmds, cmd_wc);
	return expected_cmds;
}

t_ps_node_ps_single_command_ptr *ps_create_expected_ls(void)
{
	char *argv_ls[2] = {strdup("ls"), NULL};
	t_ps_single_command *cmd_ls = create_cmd(argv_ls);
	t_ps_node_ps_single_command_ptr *expected_cmds = NULL;
	li_new_stack((void *)&expected_cmds, cmd_ls);
	return expected_cmds;
}

t_ps_node_ps_single_command_ptr *ps_create_expected_ls_cat(void)
{
	char *argv_ls[2] = {strdup("ls"), NULL};
	char *argv_cat[2] = {strdup("cat"), NULL};
	t_ps_single_command *cmd_ls = create_cmd(argv_ls);
	t_ps_single_command *cmd_cat = create_cmd(argv_cat);
	t_ps_node_ps_single_command_ptr *expected_cmds = NULL;
	li_new_stack((void *)&expected_cmds, cmd_ls);
	li_new_stack((void *)&expected_cmds, cmd_cat);
	return expected_cmds;
}

void ps_test_full_parse(char *name, char *s, t_ps_node_ps_single_command_ptr *cmds_generator())
{
	printf("%s: %s\n", name, s);
	t_ps_node_ps_single_command_ptr *expected_cmds = cmds_generator();
	t_tk_result tk_res2 = tk_tokenize(s);
	t_lx_result lx_res2 = lx_lex(tk_res2.tokens);
	t_ep_result ep_res2 = ep_expand(NULL, lx_res2.tokens);
	PS_test_parse(&ep_res2, expected_cmds);
	tk_token_free(tk_res2.tokens);
	lx_token_free(lx_res2.tokens);
	ps_free_all_cmds(expected_cmds);
}

int	main(void)
{
	ps_test_full_parse("SINGLE CMD TEST", "ls", ps_create_expected_ls);
	// ps_test_full_parse("SINGLE PIPE TEST", "ls|cat", ps_create_expected_ls_cat);
	// ps_test_full_parse("COMMAND PATH TEST", "/bin/ls", ps_create_expected_bin_ls);
	// ps_test_full_parse("EXECUTABLE TEST", "./minishell", ps_create_expected_minishell);
	// ps_test_full_parse("SLASH AND PIPE", "/bin/ls|wc", ps_create_expected_bin_wc);
	// ps_test_full_parse("COMMAND WITH OPTION", "ls -la", ps_create_expected_ls_option);
	// ps_test_full_parse("COMMAND WITH OPTION", "echo hi bye", ps_create_expected_echo_hi_bye);
	return (0);
}
