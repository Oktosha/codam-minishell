/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:16:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/02 17:45:45 by elenavoroni   ########   odam.nl         */
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

typedef struct s_PS_dummy_cmd {
	t_li_node			*argv;
	t_li_node			*inputs;
	t_li_node			*outputs;
} 	t_PS_dummy_cmd;

void	PS_print_cmds(char *cmd, int i)
{
	printf("[%d]: ", i);
	fflush(stdout);
	if (mini_putstr_fd(cmd, 1) == -1)
		mini_putstr_fd("Write error\n", 2);
	if (write(1, "\n", 1) == -1)
		mini_putstr_fd("Write error\n", 2);
}

int PS_are_dummy_equal(t_PS_dummy_cmd expected, t_ps_single_command real, int i)
{
	char *exp_cmd = NULL;
	char *real_cmd = NULL;
	int expected_s_len = mini_strlen(expected.argv->data);
	int	real_len = mini_strlen(real.argv->data);
	if (expected_s_len != real_len)
	{
		printf("mismatch at cmd nr: %d\n", i);
		printf("expected length: %d\n", expected_s_len);
		printf("real length: %d\n", real_len);
		return 0;
	}
	for(int j = 0; j <= i; ++j)
	{
		exp_cmd = mini_substr(expected.argv->data, expected_s_len);
		real_cmd = mini_substr(real.argv->data, real_len);
		PS_print_cmds(real_cmd, i);
		if (exp_cmd[j] != real_cmd[j])
		{
			printf("mismatch at cmd nr: %d\n", j);
			printf("mismatch at length: %d\n", j);
			return 0;
		}
		expected.argv = expected.argv->next;
		real.argv = real.argv->next;
	}
	return 1;
}

void	PS_test_parse(t_ep_result *ep_res, t_PS_dummy_cmd *expected, int len)
{
	t_ps_result res = ps_parse(ep_res->tokens);
	t_li_node 	*cur = res.cmds;
	// printf("PS Result commands:\n");
	for (int i = 0; i < len; ++i)
	{
		t_ps_single_command *cur_cmd = cur->data;
		if (!PS_are_dummy_equal(expected[i], *cur_cmd, i))
		{
			exit(1);
		}
		cur = cur->next;
	}
	ps_cmds_free(cur);
}

int	main(void)
{
	t_ks_kotistate *kotistate;
	t_li_node		*cmds;

	kotistate = NULL;
	// printf("SINGLE COMMAND TEST:\n");
	// cmds = li_new_list("ls -la");
	// if (!cmds)
	// {
	// 	return (-1);
	// }
	// t_PS_dummy_cmd expected1[1] = {
	// 	{cmds, NULL, NULL},
	// };
	// t_tk_result tk_res1 = tk_tokenize("ls -la");
	// t_lx_result lx_res1 = lx_lex(tk_res1.tokens);
	// t_ep_result ep_res1 = ep_expand(kotistate, lx_res1.tokens);
	// PS_test_parse(&ep_res1, expected1, 1);
	// free(cmds);
	printf("SINGLE PIPE TEST:\n");
	cmds = NULL;
	li_new_stack(&cmds, "ls");
	li_new_stack(&cmds, "cat");
	if (!cmds)
	{
		return (-1);
	}
	t_PS_dummy_cmd expected2[1] = {
		{cmds, NULL, NULL},
	};
	t_tk_result tk_res2 = tk_tokenize("ls|cat");
	t_lx_result lx_res2 = lx_lex(tk_res2.tokens);
	t_ep_result ep_res2 = ep_expand(kotistate, lx_res2.tokens);
	PS_test_parse(&ep_res2, expected2, 2);
	return (0);
}
