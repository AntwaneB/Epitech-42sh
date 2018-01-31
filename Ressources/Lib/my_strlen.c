/*
** my_strlen.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:32:38 2014 Antoine Buchser
** Last update Thu Mar 20 17:33:16 2014 Antoine Buchser
*/

#include "mini.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
