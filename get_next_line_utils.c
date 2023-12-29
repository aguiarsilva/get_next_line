/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:38:22 by baguiar-          #+#    #+#             */
/*   Updated: 2023/12/29 23:29:25 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char  *ft_strchr(const char *s, int c)
{
  while ((char)c != *s)
  {
    if (!*s)
      return (NULL);
    s++;
  }
  return ((char *)s);
}

char  *ft_strdup(char *s1)
{
  char    *s2;
  size_t  i;

  s2 = (char *)malloc(sizeof(char)*(ft_strlen(s1) + 1));
  if (!s2)
    return (NULL);
  i = 0;
  while (s1[i])
  {
    s2[i] = s1[i];
    i++;
  }
  s2[i] = '\0';
  return (s2);
}

size_t  ft_strlen(const char *str)
{
  size_t  len;

  len = 0;
  while (str[len])
    len++;
  return (len);
}

char  *ft_substr(char const *s, unsigned int start, size_t len)
{
  size_t  i;
  char    *s2;

  if (!s)
    return (NULL);
  if (start > ft_strlen(s))
    return (ft_strdup(""));
  if (len > ft_strlen(s + start))
    len = ft_strlen(s + start);
  s2 = (char *)malloc((len + 1) * sizeof(char));
  if (!s2)
    return (NULL);
  i = 0;
  while (i < len)
  {
    s2[i] = s[start + i];
    i++;
  }
  return (s2);
}

char  *ft_strjoin(char const *s1, char const *s2)
{
  char  *str;
  int   lens1;
  int   lens2;
  int   j;
  int   i;

  lens1 = ft_strlen(s1);
  lens2 = ft_strlen(s2);
  i = 0;
  j = 0;
  str = (char *)malloc((lens1 + lens2 +1) * sizeof(char));
  if (!str)
    return (NULL);
  while (s1[i])
    str[j++] = s1[i++];
  i = 0;
  while (s2[i])
    str[j++] = s2[i++];
  str[j] = '\0';
  return (str);
}

