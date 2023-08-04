/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 21:58:41 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/07/31 22:45:20 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*l_ex_extract_dir_by_len(char *s, int len)
{
	char	*dir;
	int		i;

	dir = mini_malloc(sizeof(char) * (len + 2));
	if (dir == NULL)
		return (NULL);
	dir[len] = '/';
	dir[len + 1] = '\0';
	i = 0;
	while (i < len)
	{
		dir[i] = s[i];
		i += 1;
	}
	return (dir);
}

char	*l_ex_extract_first_dir(char **sp)
{
	char	*s;
	int		len;

	s = *sp;
	len = 0;
	while (s[len] != '\0' && s[len] != ':')
		++len;
	*sp = s + len;
	if (len == 0)
		return (mini_strdup(""));
	return (l_ex_extract_dir_by_len(s, len));
}

char	*l_ex_extract_dir(char **sp)
{
	char	*s;
	int		end_position;

	s = *sp;
	end_position = 1;
	while (s[end_position] != '\0' && s[end_position] != ':')
		++end_position;
	*sp = s + end_position;
	if (end_position == 1)
		return (mini_strdup(""));
	return (l_ex_extract_dir_by_len(s + 1, end_position - 1));
}

char	**l_ex_extract_dir_candidates(char *s)
{
	int		n_dirs;
	char	**dirs;
	int		i;

	n_dirs = l_ex_count_char(s, ':') + 1;
	dirs = mini_malloc((n_dirs + 1) * sizeof(char *));
	if (dirs == NULL)
		return (NULL);
	dirs[0] = l_ex_extract_first_dir(&s);
	if (dirs[0] == NULL)
		return (mini_free(dirs));
	dirs[n_dirs] = NULL;
	i = 0;
	while (++i < n_dirs)
	{
		dirs[i] = l_ex_extract_dir(&s);
		if (dirs[i] == NULL)
			return (l_ex_free_array(dirs, i));
	}
	return (dirs);
}

char	**l_ex_get_cmd_candidates(char *cmd, char *path_value)
{
	char	**dir_candidates;
	char	**cmd_candidates;

	if (mini_find(cmd, '/') != -1)
		return (l_ex_one_value_string_array(cmd));
	dir_candidates = l_ex_extract_dir_candidates(path_value);
	if (dir_candidates == NULL)
		return (NULL);
	cmd_candidates = l_ex_add_suffix_to_all(dir_candidates, cmd);
	l_ex_free_array(dir_candidates, l_ex_n_records_before_null(dir_candidates));
	return (cmd_candidates);
}
