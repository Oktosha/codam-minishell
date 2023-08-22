/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_c.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 12:57:58 by codespace     #+#    #+#                 */
/*   Updated: 2023/08/22 16:46:00 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

int	l_lx_closed_quote_check(t_li_node *tk_tk)
{
	int			count;
	t_tk_token	*token;

	count = 0;
	while (tk_tk)
	{
		token = tk_tk->data;
		if (token->type == TK_QUOTE_2)
			count++;
		tk_tk = tk_tk->next;
	}
	if ((count % 2) == 0)
		return (0);
	return (1);
}

t_lx_state	l_lx_next_state(t_tk_token_type type)
{
	if (type == TK_EOL);
		
}


void	l_lx_err_unclosed_quote(t_lx_so_far *so_far)
{
	so_far->status = LX_ERR_SYNTAX;
	mini_putstr_fd("Syntax error, unclosed quote\n", 2);
}
