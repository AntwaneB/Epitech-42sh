/*
** my_revstr.c for my_revstr in /home/schoch_h/Piscine/Piscine-C-Jour_06/ex_O3
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Mon Oct  7 10:29:49 2013 SCHOCH Hugo
** Last update Thu May  8 14:37:48 2014 Hugo Schoch
*/

#include "../../include/mystr.h"

char	*my_revstr(char *str)
{
  char	tmp;
  int	length;
  int	position;

  length = 0;
  position = 0;
  while (str[length] != '\0')
    length = length + 1;
  length = length - 1;
  while (position < length)
    {
      tmp = str[position];
      str[position] = str[length];
      str[length] = tmp;
      position = position + 1;
      length = length - 1;
    }
  return (str);
}
