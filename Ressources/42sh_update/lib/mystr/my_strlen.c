/*
** my_strlen.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:32:38 2014 Antoine Buchser
** Last update Fri May  9 23:18:47 2014 Hugo Schoch
*/

#include "../../include/mystr.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
