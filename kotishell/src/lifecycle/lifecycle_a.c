/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lifecycle_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 16:18:32 by elenavoroni   #+#    #+#                 */
/*   Updated: 2023/07/25 16:07:32 by elenavoroni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lifecycle.h"

/** @brief start shell programm
 * @param argc number of arguments given to program
 * @param argv argument givent to program
 * @param envp enviroment variable
 * @return shell running on loop
*/
void	lc_start_shell(int argc, char **argv, char **envp)
{
	char			*line;
	t_tk_result		tk_tokens;
	t_lx_result		lx_tokens;
	t_ep_result		ep_tokens;
	t_ps_result		ps_result;
	t_ks_kotistate	kotistate;

	(void) argc;
	(void) argv;
	(void) envp;
	while (1)
	{
		line = readline("kotishell: ");
		if (!line)
			exit (EXIT_SUCCESS);
		tk_tokens = tk_tokenize(line);
		if (tk_tokens.status != TK_SUCCESS)
			continue ;
		lx_tokens = lx_lex(tk_tokens.tokens);
		if (!lx_tokens.status != LX_SUCCESS)
			continue ;
		ep_tokens = ep_expand(&kotistate, lx_tokens.tokens);
		if (ep_tokens.status != EP_SUCCESS)
			continue ;
		ps_result = ps_parse(ep_tokens.tokens);
		if (ps_result.status != PS_SUCCESS)
			continue ;
		ex_execute(&kotistate, ps_result.cmds);
		add_history(line);
	}
}
