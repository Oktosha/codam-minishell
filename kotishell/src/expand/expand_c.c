/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_c.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/14 14:27:20 by evoronin      #+#    #+#                 */
/*   Updated: 2023/08/16 15:05:37 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

t_ep_state	l_ep_next_state(t_lx_token_type lx_tk)
{
	if (lx_tk == LX_EOL)
		return (EP_ST_END);
	if (lx_tk == LX_WORD || lx_tk == LX_OTHER)
		return (EP_ST_WORD);
	if (lx_tk == LX_WHITESPACE)
		return (EP_ST_WHITESPACE);
	if (lx_tk == LX_BAD)
		return (EP_ST_ERROR);
	if (lx_tk == LX_HEREDOC)
		return (EP_ST_HEREDOC);
	if (lx_tk == LX_OUTPUT || lx_tk == LX_INPUT || lx_tk == LX_APPEND)
		return (EP_ST_IMPORTANT);
	if (lx_tk == LX_QUOTE_1 || lx_tk == LX_QUOTE_2)
		return (EP_ST_IMPORTANT);
	if (lx_tk == LX_VARIABLE)
		return (EP_ST_VARIABLE);
	if (lx_tk == LX_PIPE)
		return (EP_ST_PIPE);
	return (EP_ST_ERROR);
}

void	l_ep_error_cleanup(t_li_node *lx_res, t_ep_so_far *so_far)
{
	lx_token_free(lx_res);
	ep_token_free(so_far->head);
	so_far->head = NULL;
	mini_putstr_fd("Failed malloc\n", 2);
}
