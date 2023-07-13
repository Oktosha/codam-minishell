/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 18:55:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/13 18:01:37 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include "tokenize.h"
#include "lists.h"
#include "minilibft.h"

typedef struct s_TK_dummy_token {
	char *s;
	t_tk_token_type type;
} t_TK_dummy_token;

int TK_are_dummy_equal(t_TK_dummy_token expected, t_tk_token real, int i)
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

void TK_test_tokenize(char *input, t_TK_dummy_token *expected, int len)
{
	t_tk_result res = tk_tokenize(input);
	t_li_node *cur = res.tokens;
	for (int i = 0; i < len; ++i)
	{
		t_tk_token *cur_token = cur->data;
		if (!TK_are_dummy_equal(expected[i], *cur_token, i))
		{
			exit(1);
		}
		cur = cur->next;
	}
	li_list_free(res.tokens);
}

int	main(void)
{
	t_TK_dummy_token expected[6] = {
		{"\t\t\t\t\t ", TK_WHITESPACE},
		{"asfa", TK_WORD},
		{" ", TK_WHITESPACE},
		{"tt", TK_WORD},
		{"    ", TK_WHITESPACE},
		{"", TK_EOL}
	};
	TK_test_tokenize("\t\t\t\t\t asfa tt    ", expected, 6);
	return (0);
} //TODO chceck EOL token - it's not printed right now
