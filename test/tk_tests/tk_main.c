/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 18:55:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/08/10 16:54:15 by codespace     ########   odam.nl         */
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
		mini_write(1, token->data, token->length);
		mini_write(1, "\n", 2);
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
	printf("TK Result tokens:\n");
	TK_print_list(res.tokens);
	for (int i = 0; i < len; ++i)
	{
		t_tk_token *cur_token = cur->data;
		if (cur_token->type == TK_BAD)
			break ;
		if (!TK_are_dummy_equal(expected[i], *cur_token, i))
		{
			exit(1);
		}
		cur = cur->next;
	}
	tk_token_free(res.tokens);
}

int	main(void)
{
	printf("SIMPLE TEST:\n");
	t_TK_dummy_token expected1[3] = {
		{"ls", TK_WORD},
		{"|", TK_PIPE},
		{"cat", TK_WORD},
	};
	TK_test_tokenize("ls|cat", expected1, 3);
	// printf("EMPTY STR TEST:\n");
	// t_TK_dummy_token expected2[1] = {
	// 	{"", TK_EOL},
	// };
	// TK_test_tokenize("", expected2, 1);
	// printf("ONE PIPE TEST:\n");
	// t_TK_dummy_token expected3[6] = {
	// 	{"echo", TK_WORD},
	// 	{" ", TK_WHITESPACE},
	// 	{"|", TK_PIPE},
	// 	{" ", TK_WHITESPACE},
	// 	{"cat", TK_WORD},
	// 	{"", TK_EOL},
	// };
	// TK_test_tokenize("echo | cat", expected3, 6);
	// printf("TWO PIPES TEST\n");
	// t_TK_dummy_token expected4[3] = {
	// 	{"|", TK_PIPE},
	// 	{"|", TK_PIPE},
	// 	{"", TK_EOL},
	// };	
	// TK_test_tokenize("||", expected4, 3);
	// printf("OTHER CHAR TEST\n");
	// t_TK_dummy_token expected5[3] = {
	// 	{"$", TK_DOLLAR},
	// 	{"&@", TK_OTHER},
	// 	{"", TK_EOL},
	// };	
	// TK_test_tokenize("$&@", expected5, 3);
	// printf("NEWLINE TEST\n");
	// t_TK_dummy_token expected6[6] = {
	// 	{"\n", TK_NEWLINE},
	// 	{"&@", TK_OTHER},
	// 	{"\"", TK_QUOTE_2},
	// 	{"abcdsd1234", TK_WORD},
	// 	{"\"", TK_QUOTE_2},
	// 	{"", TK_EOL},
	// };	
	// TK_test_tokenize("\n&@\"abcdsd1234\"", expected6, 6);
	// printf("UNSUPORTED TEST\n");
	// t_TK_dummy_token expected7[7] = {
	// 	{"&@", TK_OTHER},
	// 	{"\"", TK_QUOTE_2},
	// 	{"\xf0\x9f\x98\x87", TK_BAD},
	// 	{"?", TK_QUESTION},
	// 	{"\"", TK_QUOTE_2},
	// 	{"?", TK_QUESTION},
	// 	{"", TK_EOL},
	// };	
	// TK_test_tokenize("&@\"😇?\"?", expected7, 7);
	return (0);
}
