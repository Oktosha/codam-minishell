/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ep_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:16:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/16 15:10:37 by codespace     ########   odam.nl         */
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
		mini_write(1, token->data, token->length);
		mini_write(1, "\n", 2);
		list = list->next;
		i++;
	}
}

int EP_are_dummy_equal(t_EP_dummy_token expected, t_ep_token real, int i)
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

void	EP_test_expand(t_ks_kotistate *kotistate, t_lx_result *lx_res, t_EP_dummy_token *expected, int len)
{
	t_ep_result res = ep_expand(kotistate, lx_res->tokens);
	t_li_node 	*cur = res.tokens;
	EP_print_list(res.tokens);
	for (int i = 0; i < len; ++i)
	{
		t_ep_token *cur_token = cur->data;
		if (cur_token->type == EP_BAD)
			break ;
		if (!EP_are_dummy_equal(expected[i], *cur_token, i))
		{
			exit(1);
		}
		cur = cur->next;
	}
	ep_token_free(res.tokens);
	lx_token_free(lx_res->tokens);
}

int	main(void)
{
	// printf("SIMPLE TEST:\n");
	// t_EP_dummy_token expected1[1] = {
	// 	{"/bin/ls", EP_WORD},
	// };
	// t_tk_result tk_res1 = tk_tokenize("/bin/ls");
	// t_lx_result lx_res1 = lx_lex(tk_res1.tokens);
	// tk_token_free(tk_res1.tokens);
	// EP_test_expand(NULL, &lx_res1, expected1, 1);
	
	// printf("MORE SIMPLE TEST:\n");
	// t_EP_dummy_token expected4[1] = {
	// 	{"./minishell", EP_WORD},
	// };
	// t_tk_result tk_res4 = tk_tokenize("./minishell");
	// t_lx_result lx_res4 = lx_lex(tk_res4.tokens);
	// tk_token_free(tk_res4.tokens);
	// EP_test_expand(NULL, &lx_res4, expected4, 1);

	// printf("PIPE TEST:\n");
	// t_EP_dummy_token expected2[3] = {
	// 	{"ls", EP_WORD},
	// 	{"|", EP_PIPE},
	// 	{"cat", EP_WORD}
	// };
	// t_tk_result tk_res2 = tk_tokenize("ls|cat");
	// t_lx_result lx_res2 = lx_lex(tk_res2.tokens);
	// tk_token_free(tk_res2.tokens);
	// EP_test_expand(NULL, &lx_res2, expected2, 3);
	
	printf("CMND with ARG TEST:\n");
	t_EP_dummy_token expected3[2] = {
		{"echo", EP_WORD},
		{"hello", EP_WORD},
	};
	t_tk_result tk_res3 = tk_tokenize("echo hello");
	t_lx_result lx_res3 = lx_lex(tk_res3.tokens);
	tk_token_free(tk_res3.tokens);
	EP_test_expand(NULL, &lx_res3, expected3, 2);
	return (0);
}
