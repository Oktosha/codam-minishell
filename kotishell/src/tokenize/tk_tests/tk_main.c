/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 18:55:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/12 18:35:59 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include "tokenize.h"

typedef struct s_TK_dummy_token {
	char *s;
	t_tk_token_type type;
} t_TK_dummy_token;

int TK_are_dummy_equal(t_TK_dummy_token expected, t_tk_token real)
{
	if (expected.type != real.type)
	{
		printf("token types don't match\n");
		return 0;
	}
	int expected_s_len = mini_strlen(expected.s);
	if (expected_s_len != real.length)
	{
		printf("token lengths don't match\n");
		return 0;
	}
	for(int i = 0; i < real.length; ++i)
	{
		if (expected.s[i] != real.data[i])
		{
			printf("token data mismatch\n");
			return 0;
		}
	}
	return 1;
}

void TK_test_tokenize(char *input, t_TK_dummy_token *expected, int len)
{
	// TODO: compare lengths
	// TODO: check null insead of segfault
	t_tk_result res = tk_tokenize(input);
	t_li_node *cur = res.tokens;
	for (int i = 0; i < len; ++i)
	{
		t_tk_token *cur_token = cur->data;
		if (!TK_are_dummy_equal(expected[i], *cur_token))
		{
			printf("mismatch at %d\n", i);
			printf("expected type: %d\n", expected[i].type);
			printf("real type: %d\n", cur_token->type);
			exit(1);
		}
		cur = cur->next;
	}
	li_list_free(res.tokens);
}

int	main(void)
{
	// tk_tokenize(" what");
	// printf("\n");
	// tk_tokenize("");
	// printf("\n");
	
	t_TK_dummy_token expected[6] = {
		{"\t\t\t\t\t ", TK_WHITESPACE},
		{"asfa", TK_WORD},
		{" ", TK_WHITESPACE},
		{"tt", TK_WORD},
		{"    ", TK_WHITESPACE},
		{"", TK_EOL}
	};
	TK_test_tokenize("\t\t\t\t\t asfa tt    ", expected, 6);
	// printf("\n");
	return (0);
} //TODO chceck EOL token - it's not printed right now
