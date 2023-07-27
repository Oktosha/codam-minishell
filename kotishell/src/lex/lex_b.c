/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_b.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 12:08:29 by codespace     #+#    #+#                 */
/*   Updated: 2023/07/27 11:40:05 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

void	l_lx_quotes_2(t_lx_so_far *so_far, t_tk_result *tk_res)
{
	t_li_node	*tk_tk;
	t_tk_token	*tk_token;

	tk_tk = tk_res->tokens;
	if (so_far->status != LX_SUCCESS)
		return ;
	while (tk_res)
	{
		tk_token = tk_tk->data;
		while (tk_token->type != TK_QUOTE_2)
		{
			so_far->token.type = LX_QUOTE_2;
			so_far->token.data = tk_token->data;
			so_far->token.length += tk_token->length;
		}
		tk_tk = tk_res->tokens->next;
		else
			l_lx_err_unclosed_quote(so_far);
	}
}//TO_DO: after this step, check variables within quote states

void	l_lx_token_result(t_lx_result *result, t_lx_so_far *so_far)
{
	result->tokens = so_far->head;
	result->status = so_far->status;
}
