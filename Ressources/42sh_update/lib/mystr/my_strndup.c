/*
** my_strdup.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:42:55 2014 Antoine Buchser
** Last update Fri May  9 23:19:02 2014 Hugo Schoch
*/

#include <stdlib.h>
#include "../../include/mystr.h"

char	*my_strndup(char *str, int n)
{
  int	i;
  char	*dest;

  n = (my_strlen(str) < n) ? my_strlen(str) : n;
  if ((dest = malloc((n + 1) * sizeof(*dest))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] && i < n)
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
