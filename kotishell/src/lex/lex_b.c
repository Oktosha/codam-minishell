/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_b.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/26 12:08:29 by codespace     #+#    #+#                 */
/*   Updated: 2023/07/26 14:25:43 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

void    

void    l_lx_quotes_1(t_lx_so_far *so_far, t_tk_token *tk_token)
{
    if (so_far->status != LX_SUCCESS)
        return ;
    while (tokens.data.type != TK_QUOTE_1)
    {
        so_far->token.type = TK_QUOTE_1;
        so_far->token.data = tokens->data.data;
        so_far->token.length += tokens->data.length;
        tokens->data = tokens->next;
    }
    else
        l_lx_err_unclosed_quote(so_far);
        
}//TO_DO: after this step, check variables within quote states

void	l_lx_token_result(t_lx_result *result, t_lx_so_far *so_far)
{
	result->tokens = so_far->head;
	result->status = so_far->status;
}