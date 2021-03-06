/*
** my_strdup.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:42:55 2014 Antoine Buchser
** Last update Thu Mar 20 18:33:02 2014 Antoine Buchser
*/

#include <stdlib.h>
#include "mini.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*dest;

  if ((dest = malloc((my_strlen(str) + 1) * sizeof(*dest))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    dest[i] = str[i];
  dest[i] = '\0';
  return (dest);
}
