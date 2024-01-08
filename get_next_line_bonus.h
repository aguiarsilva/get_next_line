/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:20:00 by baguiar-          #+#    #+#             */
/*   Updated: 2024/01/05 14:20:03 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
#endif
# define MAX_FD 10240
# include <stdlib.h>
# include <unistd.h>

char  *get_next_line(int fd);
char  *ft_strchr(const char *s, int c);
char  *ft_strdup(char *s1);
size_t  ft_strlen(const char *str);
char  *ft_substr(char const *s, unsigned int start, size_t len);
char  *ft_strjoin(char const *s1, char const *s2);

#endif
