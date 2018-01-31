/*
** my_strdup.c for my_strdup in /home/buchse_a/Documents/Piscine-C-Jour_08
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Wed Oct  9 10:10:44 2013 Antoine Buchser
** Last update Sat May 24 13:30:28 2014 François KIENE
*/

#include <stdlib.h>

char	*my_strndup(char *src, int len)
{
  char	*dest;
  int	i;

  if ((dest = malloc((len + 1) * sizeof(*dest))) == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0' && i < len)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
