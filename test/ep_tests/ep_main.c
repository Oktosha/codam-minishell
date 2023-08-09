/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ep_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:16:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/09 16:25:49 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include "lex.h"
#include "lists.h"
#include "minilibft.h"
#include "tokenize.h"
#include "expand.h"

typedef struct s_EP_dummy_token {
	char *s;
	t_ep_token_type type;
} t_EP_dummy_token;

void	EP_print_list(t_li_node *list)
{
	t_ep_token	*token;
	int			i;

	i = 0;
	while (list)
	{
		token = list->data;
		printf("[%d]: ", i);
		fflush(stdout);
		if (write(1, token->data, token->length) == -1)
			mini_putstr_fd("Write error\n", 2);
		if (write(1, "\n", 2) == -1)
			mini_putstr_fd("Write error\n", 2);
		list = list->next;
		i++;
	}
}

int LX_are_dummy_equal(t_EP_dummy_token expected, t_ep_token real, int i)
{
	if (expected.type != real.type)
	{
		printf("mismatch at token nr: %d\n", i);
		printf("expected type: %d\n", expected.type);
		printf("real type: %d\n", real.type);
		return 0;
	}
	int expected_s_len = mini_strlen(expected.s);
	if (expected_s_len != real.length)
	{
		printf("mismatch at token nr: %d\n", i);
		printf("expected length: %d\n", expected_s_len);
		printf("real length: %d\n", real.length);
		return 0;
	}
	for(int i = 0; i < real.length; ++i)
	{
		if (expected.s[i] != real.data[i])
		{
			printf("mismatch at token nr: %d\n", i);
			printf("mismatch at length: %d\n", i);
			return 0;
		}
	}
	return 1;
}

void	LX_test_tokenize(t_ks_kotistate *kotistate, t_lx_result *lx_res, t_EP_dummy_token *expected, int len)
{
	t_ep_result res = ep_expand(kotistate, lx_res->tokens);
	t_li_node 	*cur = res.tokens;
	printf("EP Result tokens:\n");
	EP_print_list(res.tokens);
	for (int i = 0; i < len; ++i)
	{
		t_ep_token *cur_token = cur->data;
		if (cur_token->type == LX_BAD)
			break ;
		if (!LX_are_dummy_equal(expected[i], *cur_token, i))
		{
			exit(1);
		}
		cur = cur->next;
	}
	ep_token_free(res.tokens);
}

int	main(void)
{
	// printf("SIMPLE TEST:\n");
	// t_EP_dummy_token expected1[1] = {
	// 	{"whatever", EP_WORD},
	// };
	// t_tk_result tk_res1 = tk_tokenize("whatever");
	// t_lx_result lx_res1 = lx_lex(tk_res1.tokens);
	// LX_test_tokenize(NULL, &lx_res1, expected1, 1);
	printf("PIPE TEST:\n");
	t_EP_dummy_token expected2[3] = {
		{"ls", EP_WORD},
		{"|", EP_PIPE},
		{"cat", EP_WORD},
	};
	t_tk_result tk_res2 = tk_tokenize("ls|cat");
	t_lx_result lx_res2 = lx_lex(tk_res2.tokens);
	LX_test_tokenize(NULL, &lx_res2, expected2, 3);
	return (0);
}
