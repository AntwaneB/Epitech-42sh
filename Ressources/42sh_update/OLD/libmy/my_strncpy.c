/*
** my_strncpy.c for my_strncpy in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Oct  7 09:48:00 2013 Antoine Buchser
** Last update Thu Apr 24 20:50:27 2014 Antoine Buchser
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (n > my_strlen(src))
    dest[i + 1] = '\0';
  return (dest);
}
