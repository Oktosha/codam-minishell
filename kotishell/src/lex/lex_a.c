/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_a.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 14:19:41 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/27 11:38:50 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

void	l_lx_token_copy(t_tk_so_far *so_far)
{
	t_tk_token	*ptr_token;

	ptr_token = malloc(sizeof(t_tk_token));
	if (!ptr_token)
	{
		so_far->status = TK_ERR_MALLOC;
		return ;
	}
	ptr_token->data = so_far->token.data;
	ptr_token->length = so_far->token.length;
	ptr_token->type = so_far->token.type;
	if (li_new_stack(&so_far->head, ptr_token) == -1)
	{
		so_far->status = TK_ERR_MALLOC;
		free(ptr_token);
		return ;
	}
}

void	lx_token_free(t_li_node *list)
{
	t_li_node	*temp;

	while (list)
	{
		temp = list;
		free(temp->data);
		list = list->next;
		free(temp);
	}
}

void	l_lx_init_so_far(t_lx_so_far *so_far)
{
	so_far->status = LX_SUCCESS;
	so_far->head = NULL;
	so_far->token.type = LX_EMPTY;
	so_far->token.length = 0;
	so_far->state = LX_ST_START;
	so_far->token.data = NULL;
}

void	l_lx_start(t_lx_so_far *so_far, t_tk_result *tk_res)
{
	t_li_node	*tk_tk;
	t_tk_token	*tk_token;

	tk_tk = tk_res->tokens;
	tk_token = tk_tk->data;
	if (tk_token->type == TK_QUOTE_2)
	{
		so_far->state = LX_ST_QUOTE_2;
		l_lx_quotes_2(so_far, tk_res);
	}
}

t_lx_result	lx_lex(t_tk_result *tk_res)
{
	t_lx_result	result;
	t_lx_so_far	so_far;

	l_lx_init_so_far(&so_far);
	l_lx_start(&so_far, tk_res);
	l_lx_token_result(&result, &so_far);
	return (result);
}
