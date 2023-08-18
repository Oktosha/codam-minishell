/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 15:33:10 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/08/18 16:30:53 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "minilibft.h"


int main (void)
{
	mini_assert(mini_find("aac", 'a') == 0, "mini_find finds first symbol");
	mini_assert(mini_find("aac", 'c') == 2, "mini_find finds last symbol");
	mini_assert(mini_find("aac", '\0') == 3, "mini_find of '\\0' is length");
	mini_assert(mini_find("", 'a') == -1, "mini_find doesn't find anything in empty string");
	mini_assert(mini_find("avdsvfdvfdvb", 'Z') == -1, "mini_find returns -1 if the symbol is absent");

	char *s = mini_concat("ab", "CDEF");
	mini_assert(strcmp(s, "abCDEF") == 0, "ab + CD = abCDEF");
	free(s);

	s = mini_strdup("abc");
	mini_assert(strcmp(s, "abc") == 0, "duplicate of abc is abc");
	mini_free(s);

	char *s1 = strdup("hello");
	char *s2 = strdup(" world");
	char *res = mini_strjoin(s1, s2);
	printf("res: %s\n", res);
	mini_assert(strcmp(res, "hello world") == 0, "mini_strjoin is not working");
	free(res);
	free(s1);
	free(s2); 
	return (0);
}
