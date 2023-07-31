/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minilibft.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: elenavoronin <elnvoronin@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:23:07 by evoronin      #+#    #+#                 */
/*   Updated: 2023/07/31 21:21:28 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int			mini_putstr_fd(const char *s, int fd);
void		*mini_malloc(size_t size);
int			mini_strlen(const char *s);
void		mini_assert(int condition, const char *str);

/**
 * @brief searches for the first occurence of ch in null-terminated string s
 * @param s null-terminated string
 * @param ch character to search for
 * @return position of character in s or -1 of no such character in string
 * @note s must be a valid string, not NULL
 * @note ch can be '\0' in that case string length is returned
*/
int			mini_find(char *s, char ch);

/**
 * @brief creates (allocates) a copy of a null-terminated string s
 * @note s can't be null or any other invalid pointer
 * @return copied string or NULL on failed allocation
*/
char		*mini_strdup(const char *s);

/**
 * @brief creates (allocates) string s1s2 out of strings s1 and s2
 * @note s1 and s2 must be valid strings, not nulls
 * @note s1 and s2 may be empty strings (but must be null-terminated)
 * @return concatenated string or NULL on failed allocation 
*/
char		*mini_concat(const char *s1, const char *s2);

/**
 * @brief calls free and returns NULL; used to save lines
*/
void		*mini_free(void *p);

#endif
