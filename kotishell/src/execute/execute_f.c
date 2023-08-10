/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_f.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 16:05:06 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/08/09 15:47:06 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	l_ex_builtin(t_ks_kotistate *state, t_ps_single_command *cmd)
{
	(void) state;
	(void) cmd;
	return (0);
}

char	*l_ex_kotivar_to_str(t_ks_kotivar *var)
{
	int		len_name;
	int		len_value;
	int		i;
	char	*s;

	len_name = mini_strlen(var->name);
	len_value = mini_strlen(var->value);
	s = mini_malloc((len_name + 1 + len_value + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = -1;
	while (++i < len_name)
		s[i] = var->name[i];
	s[i] = '=';
	while (++i < (len_name + len_value + 1))
		s[i] = var->value[i - len_name - 1];
	s[len_name + len_value + 1] = '\0';
	return (s);
}

char	**l_ex_env_to_array(t_li_node *env)
{
	int				len;
	int				i;
	char			**arr;

	len = li_list_size(env);
	arr = mini_malloc((len + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[len] = NULL;
	i = 0;
	while (env)
	{
		arr[i] = l_ex_kotivar_to_str(env->data);
		if (arr[i] == NULL)
		{
			l_ex_free_array(arr, i);
			return (NULL);
		}
		env = env->next;
		i += 1;
	}
	return (arr);
}

int	l_ex_is_builtin(char *name)
{
	(void) name;
	return (0);
}
