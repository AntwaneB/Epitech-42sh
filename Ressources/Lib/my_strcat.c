/*
** my_strcat.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:38:55 2014 Antoine Buchser
** Last update Thu Mar 20 18:32:46 2014 Antoine Buchser
*/

#include <stdlib.h>
#include "mini.h"

char	*my_strcat(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*dest;

  if ((dest = malloc((my_strlen(s1) + my_strlen(s2) + 1)
		     * sizeof(*dest))) == NULL)
    return (NULL);
  j = 0;
  i = -1;
  while (++i < my_strlen(s1))
    {
      dest[j] = s1[i];
      j++;
    }
  i = -1;
  while (++i < my_strlen(s2))
    {
      dest[j] = s2[i];
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
