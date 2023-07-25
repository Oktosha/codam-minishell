/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifecycle_c.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 17:55:03 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/07/25 18:59:23 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lifecycle.h"

void	l_lc_handle_tokenize_status(t_tk_status tk_status, \
	t_ks_kotistate *kotistate, t_lc_status *lc_status)
{
	if (tk_status == TK_SUCCESS)
		return ;
	if (tk_status == TK_ERR_MALLOC)
	{
		kotistate->status_code = 42;
	}
	else if (tk_status == TK_ERR_SYMBOL)
	{
		kotistate->status_code = 27;
	}
	else
	{
		mini_assert(0, "unknown tokenize status");
	}
	*lc_status = LC_ERROR;
}

void	l_lc_handle_lex_status(t_lx_status lx_status, \
	t_ks_kotistate *kotistate, t_lc_status *lc_status)
{
	if (lx_status == LX_SUCCESS)
		return ;
	if (lx_status == LX_ERR_MALLOC)
	{
		kotistate->status_code = 42;
	}
	else if (lx_status == LX_ERR_SYNTAX)
	{
		kotistate->status_code = 258;
	}
	else
	{
		mini_assert(0, "unknown lex status");
	}
	*lc_status = LC_ERROR;
}

void	l_lc_handle_expand_status(t_lx_status ep_status, \
	t_ks_kotistate *kotistate, t_lc_status *lc_status)
{
	if (ep_status == EP_SUCCESS)
		return ;
	if (ep_status == EP_ERR_MALLOC)
	{
		kotistate->status_code = 42;
	}
	else
	{
		mini_assert(0, "unknown expand status");
	}
	*lc_status = LC_ERROR;
}

void	l_lc_handle_parse_status(t_ps_status ps_status, \
	t_ks_kotistate *kotistate, t_lc_status *lc_status)
{
	if (ps_status == PS_SUCCESS)
		return ;
	if (ps_status == PS_ERR_MALLOC)
	{
		kotistate->status_code = 42;
	}
	else
	{
		mini_assert(0, "unknown parse status");
	}
	*lc_status = LC_ERROR;
}
