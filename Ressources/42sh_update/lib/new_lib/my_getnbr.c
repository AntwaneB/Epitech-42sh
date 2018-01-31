/*
** my_getnbr.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 18:10:46 2014 Antoine Buchser
** Last update Thu Mar 20 18:32:18 2014 Antoine Buchser
*/

#include "mini.h"

int	get_nb_signs(char *str)
{
  int	i;

  i = 0;
  while (str[i] == '-' || str[i] == '+')
    i++;
  return (i);
}

int	get_nb_minus(char *str)
{
  int	nb_minus;
  int	i;

  nb_minus = 0;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	nb_minus++;
      i++;
    }
  return (nb_minus);
}

long	my_getnbr(char *str)
{
  long	result;
  int	i;
  int	nb_minus;

  result = 0;
  nb_minus = get_nb_minus(str);
  str += get_nb_signs(str);
  i = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      result = result * 10 + str[i] - '0';
      i++;
    }
  return ((nb_minus % 2 != 0) ? -result : result);
}
