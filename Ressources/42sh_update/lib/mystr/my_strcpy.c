/*
** my_strcpy.c for my_strcpy in /home/schoch_h/Piscine/Piscine-C-Jour_06/ex_O1
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Mon Oct  7 08:47:07 2013 SCHOCH Hugo
** Last update Thu May  8 14:37:44 2014 Hugo Schoch
*/

#include "../../include/mystr.h"

char	*my_strcpy(char *dest, char *src)
{
  int	position;

  position = 0;
  while (src[position] != '\0')
    {
      dest[position] = src[position];
      position = position + 1;
    }
  dest[position] = '\0';
  return (dest);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	position;

  position = 0;
  while (position < n)
    {
      if (dest[position] == '\0')
	return (dest);
      dest[position] = src[position];
      position = position + 1;
    }
  dest[position] = '\0';
  return (dest);
}
