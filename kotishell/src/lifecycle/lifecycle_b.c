/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifecycle_b.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 17:53:02 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/08/02 15:38:12 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lifecycle.h"

void	l_lc_process_data_cleanup(t_lc_process_data *data)
{
	tk_token_free(data->tk_result.tokens);
	lx_token_free(data->lx_result.tokens);
	ep_token_free(data->ep_result.tokens);
	ps_cmds_free(data->ps_result.cmds);
}

void	l_lc_init_process_data(t_lc_process_data *data)
{
	data->tk_result.tokens = NULL;
	data->lx_result.tokens = NULL;
	data->ep_result.tokens = NULL;
	data->ps_result.cmds = NULL;
}

void	l_lc_process_line(char *line, t_ks_kotistate *kotistate)
{
	t_lc_process_data	data;
	t_lc_status			status;

	status = LC_SUCCESS;
	l_lc_init_process_data(&data);
	data.tk_result = tk_tokenize(line);
	l_lc_handle_tokenize_status(data.tk_result.status, kotistate, &status);
	if (status == LC_SUCCESS)
	{
		data.lx_result = lx_lex(data.tk_result.tokens);
		l_lc_handle_lex_status(data.lx_result.status, kotistate, &status);
	}
	if (status == LC_SUCCESS)
	{
		data.ep_result = ep_expand(kotistate, data.lx_result.tokens);
		l_lc_handle_expand_status(data.ep_result.status, kotistate, &status);
	}
	if (status == LC_SUCCESS)
	{
		data.ps_result = ps_parse(data.ep_result.tokens);
		l_lc_handle_parse_status(data.ps_result.status, kotistate, &status);
	}
	if (status == LC_SUCCESS)
		kotistate->status_code = ex_execute(kotistate, data.ps_result.cmds);
	l_lc_process_data_cleanup(&data);
}
