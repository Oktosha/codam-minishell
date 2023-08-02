/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_e.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/01 17:17:21 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/08/02 16:50:30 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	*l_ex_cleanup_pipes(int n_pipes, t_ex_pipe_array *pipes)
{
	int i;

	i = 1;
	while (i <= n_pipes)
	{
		close((*pipes)[i][1]);
		close((*pipes)[i][0]);
		i += 1;
	}
	free(*pipes);
	*pipes = NULL;
	return (NULL);
}

t_ex_pipe_array l_ex_create_pipes(int n_pipes)
{
	t_ex_pipe_array	pipes;
	int				i;

	pipes = mini_malloc((n_pipes + 2) * sizeof(*pipes));
	if (pipes == NULL)
	{
		printf("TODO: malloc error creating pipes array\n");
		return (NULL);
	}
	pipes[0][0] = STDIN_FILENO;
	pipes[n_pipes + 1][1] = STDOUT_FILENO;
	i = 1;
	while (i <= n_pipes)
	{
		if (pipe(pipes[i]) == -1)
		{
			printf("TODO: pipe error creating pipe %d in pipe array\n", i);
			return (l_ex_cleanup_pipes(i, &pipes));
		}
		i += 1;
	}
	return (pipes);
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
	while(++i < len_name)
		s[i] = var->name[i];
	s[i] = '=';
	while(++i < (len_name + len_value + 1))
		s[i] = var->value[i - len_name - 1];
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
