/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:38:09 by baguiar-          #+#    #+#             */
/*   Updated: 2024/01/03 08:53:08 by baguiar-         ###   ########.fr       */
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

char  *get_next_line(int fd)
{

}
