/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/10 14:12:29 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/26 14:19:47 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	l_tk_init_so_far(t_tk_so_far *so_far)
{
	so_far->status = TK_SUCCESS;
	so_far->head = NULL;
	so_far->token.type = TK_EMPTY;
	so_far->token.length = 0;
	so_far->state = TK_ST_START;
	so_far->token.data = NULL;
}

void	l_tk_token_copy(t_tk_so_far *so_far)
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

void	l_tk_token_result(t_tk_result *result, t_tk_so_far *so_far)
{
	result->tokens = so_far->head;
	result->status = so_far->status;
}

void	tk_token_free(t_li_node *list)
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

void	l_tk_error_cleanup(t_tk_so_far *so_far)
{
	tk_token_free(so_far->head);
	so_far->head = NULL;
	mini_putstr_fd("Failed malloc\n", 2);
}
