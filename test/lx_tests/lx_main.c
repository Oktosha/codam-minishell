/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lx_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:16:36 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/21 14:01:52 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include "lex.h"
#include "lists.h"
#include "minilibft.h"
#include "tokenize.h"

typedef struct s_LX_dummy_token {
	char *s;
	t_lx_token_type type;
} t_LX_dummy_token;

typedef struct s_TK_dummy_token {
	char *s;
	t_tk_token_type type;
} t_TK_dummy_token;


void	LX_print_list(t_lx_node_lx_token_ptr *list)
{
	int			i;
	t_lx_token	*token;

	i = 0;
	while (list)
	{
		token = list->token;
		printf("[%d]: ", i);
		fflush(stdout);
		mini_write(1, token->data,token->length);
		mini_write(1, "\n", 2);
		list = list->next;
		i++;
	}
}

int LX_are_dummy_equal(t_LX_dummy_token expected, t_lx_token real, int i)
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

void	LX_test_tokenize(t_tk_result *tk_res, t_LX_dummy_token *expected, int len)
{
	t_lx_result 			res = lx_lex(tk_res->tokens);
	t_lx_node_lx_token_ptr 	*cur = res.tokens;
	printf("LX Result tokens:\n");
	LX_print_list(res.tokens);
	for (int i = 0; i < len; ++i)
	{
		t_lx_token *cur_token = cur->token;
		if (cur_token->type == LX_BAD)
			break ;
		if (!LX_are_dummy_equal(expected[i], *cur_token, i))
		{
			exit(1);
		}
		cur = cur->next;
	}
	lx_token_free(res.tokens);
	tk_token_free(tk_res->tokens);
}

int	main(void)
{
	printf("SIMPLE TEST:\n");
	t_LX_dummy_token expected1[6] = {
		{"/", LX_OTHER},
		{"usr", LX_WORD},
		{"/", LX_OTHER},
		{"bin", LX_WORD},
		{"/", LX_OTHER},
		{"ls", LX_WORD},
	};
	t_tk_result tk_res1 = tk_tokenize("/usr/bin/ls");
	LX_test_tokenize(&tk_res1, expected1, 6);
	printf("PIPE TEST:\n");
	t_LX_dummy_token expected2[4] = {
		{"ls", LX_WORD},
		{"|", LX_PIPE},
		{"cat", LX_WORD},
		{"", LX_EOL},
	};
	t_tk_result tk_res2 = tk_tokenize("ls|cat");
	LX_test_tokenize(&tk_res2, expected2, 4);
	return (0);
}
 