/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_putstr_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:21:11 by evoronin      #+#    #+#                 */
/*   Updated: 2023/06/30 16:16:20 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	mini_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
