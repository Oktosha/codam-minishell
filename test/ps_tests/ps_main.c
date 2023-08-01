/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:16:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/01 09:03:24 by elenavoroni   ########   odam.nl         */
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

typedef struct s_PS_dummy_cmd {
	char			*argv;
	char			*inputs;
	char			*outputs;
	char			*appends;
	char			*heredoc;
} 	t_PS_dummy_cmd;

void	PS_print_cmds(t_li_node *argv)
{
	int			i;

	i = 0;
	while (argv)
	{
		printf("[%d]: ", i);
		fflush(stdout);
		if (mini_putstr_fd(argv->data, 1) == -1)
			mini_putstr_fd("Write error\n", 2);
		if (write(1, "\n", 2) == -1)
			mini_putstr_fd("Write error\n", 2);
		argv = argv->next;
		i++;
	}
}

int PS_are_dummy_equal(t_PS_dummy_cmd expected, t_ps_single_command real, int i)
{
	int expected_s_len = mini_strlen(expected.argv);
	int	real_len = mini_strlen(real.argv->data);
	if (expected_s_len != real_len)
	{
		printf("mismatch at cmd nr: %d\n", i);
		printf("expected length: %d\n", expected_s_len);
		printf("real length: %d\n", real_len);
		return 0;
	}
	for(int i = 0; i < real_len; ++i)
	{
		char *exp_cmd = expected.argv;
		char *real_cmd = real.argv->data;
		if (exp_cmd[i] != real_cmd[i])
		{
			printf("mismatch at token nr: %d\n", i);
			printf("mismatch at length: %d\n", i);
			return 0;
		}
		real.argv = real.argv->next;
	}
	return 1;
}

void	PS_test_parse(t_ep_result *ep_res, t_PS_dummy_cmd *expected, int len)
{
	t_ps_result res = ps_parse(ep_res->tokens);
	t_li_node 	*cur = res.cmds;
	printf("PS Result commands:\n");
	PS_print_cmds(res.cmds);
	for (int i = 0; i < len; ++i)
	{
		t_ps_single_command *cur_cmd = cur->data;
		if (!PS_are_dummy_equal(expected[i], *cur_cmd, i))
		{
			exit(1);
		}
		cur = cur->next;
	}
	ps_cmds_free(res.cmds);
}

int	main(void)
{
	t_ks_kotistate *kotistate;

	kotistate = NULL;
	printf("SINGLE COMMAND TEST:\n");
	t_PS_dummy_cmd expected1[1] = {
		{"ls", "", "", "", ""},
	};
	t_tk_result tk_res1 = tk_tokenize("ls");
	t_lx_result lx_res1 = lx_lex(tk_res1.tokens);
	t_ep_result ep_res1 = ep_expand(kotistate, lx_res1.tokens);
	PS_test_parse(&ep_res1, expected1, 1);
	return (0);
}
