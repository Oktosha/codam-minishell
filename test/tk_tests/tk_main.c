/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 18:55:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/17 16:29:59 by dkolodze      ########   odam.nl         */
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


void	TK_print_list(t_li_node *list)
{
	t_tk_token	*token;
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
	printf("Result status: %d\n", res.status);
	printf("Result tokens:\n");
	TK_print_list(res.tokens);
	for (int i = 0; i < len; ++i)
	{
		t_tk_token *cur_token = cur->data;
		if (!TK_are_dummy_equal(expected[i], *cur_token, i))
		{
			exit(1);
		}
		cur = cur->next;
	}
	l_tk_token_free(res.tokens);
}

int	main(void)
{
	t_TK_dummy_token expected1[6] = {
		{"\t\t\t\t\t ", TK_WHITESPACE},
		{"asfa", TK_WORD},
		{" ", TK_WHITESPACE},
		{"tt", TK_WORD},
		{"    ", TK_WHITESPACE},
		{"", TK_EOL}
	};
	TK_test_tokenize("\t\t\t\t\t asfa tt    ", expected1, 6);
	return (0);
}
