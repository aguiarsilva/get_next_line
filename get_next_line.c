/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:38:09 by baguiar-          #+#    #+#             */
/*   Updated: 2024/01/04 14:38:21 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *fill_buffer(int fd, char *lchar, char *buf)
{
  ssize_t byte;
  char    *temp;

  byte = 1;
  while (byte > 0)
  {
    byte = read(fd, buf, BUFFER_SIZE);
    if (byte == -1)
    {
      free(lchar);
      return (NULL);
    }
    else if (byte == 0)
        break;
    buf[byte] = 0;
    if (!lchar)
      lchar = ft_strdup("");
    temp = lchar;
    lchar = ft_strjoin(temp, buf);
    free(temp);
    temp = NULL;
    if (ft_strchr(buf, '\n'))
      break;
  }
  return (lchar);
}

static char	*put_line(char *line_buf)
{
  char    *stack;
  ssize_t i;

  i = 0;
  while (line_buf[i] != '\n' && line_buf[i] != '\0')
  {
    i++;
  }
  if (line_buf[i] == '\0' && line_buf[i] == '\n')
    return (NULL);
  line_buf = ft_substr(line_buf, i + 1, ft_strlen(line_buf) - i);
  if (*line_buf == 0)
  {
    free(line_buf);
    line_buf = NULL;
  }
  line_buf[i + 1] = '\0';
  return (line_buf);
}

char  *get_next_line(int fd)
{
  static char  *lchar;
  char         *buf;
  char         *line;

  buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
  if(fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
  {
    free(lchar);
    free(buf);
    lchar = NULL;
    buf = NULL;
    return (NULL);
  }
  if(!buf)
    return (NULL);
  line = fill_buffer(fd, lchar, buf);
  free(buf);
  buf = NULL;
  if (!line)
    return (NULL);
  lchar = put_line(line);
  return (line);
}
