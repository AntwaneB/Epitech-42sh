/*
** my_getnbr_base.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 18:06:13 2014 Antoine Buchser
** Last update Thu Mar 20 18:09:39 2014 Antoine Buchser
*/

#include "mini.h"

int	get_pos_b(char c, char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == c)
	return (i);
    }
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	result;
  int	baselen;
  int	strlen;
  int	fact;

  if (str[0] == '-')
    return (-my_getnbr_base(str + 1, base));
  fact = 1;
  baselen = my_strlen(base);
  strlen = my_strlen(str) - 1;
  result = 0;
  while (strlen >= 0)
    {
      result += get_pos_b(str[strlen], base) * fact;
      fact *= baselen;
      strlen--;
    }
  return (result);
}
