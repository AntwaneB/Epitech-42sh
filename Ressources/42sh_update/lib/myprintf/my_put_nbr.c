/*
** my_put_nbr.c for my_put_nbr in /home/schoch_h/Piscine/Piscine-C-Jour_03
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Wed Oct  2 15:51:00 2013 SCHOCH Hugo
** Last update Thu May  8 14:20:24 2014 Hugo Schoch
*/

#include "../../include/myprintf.h"

static int	my_pow(int nbr, int pow)
{
  int		result;

  result = 1;
  while (pow > 0)
    {
      result = result * nbr;
      pow = pow - 1;
    }
  return (result);
}

static int	display_nbr(int nb, int length, int nb_max)
{
  int		number;
  int		number_final;

  number_final = 0;
  while (length >= 0)
    {
      number = (nb / my_pow(10, length)) - (number_final * 10);
      number_final = (number_final * 10) + number;
      if ((length == 0) && (nb_max == 1))
  	{
  	  number = number + 1;
  	}
      length = length - 1;
      if (number == 10)
	{
	  my_putchar(1 + '0');
	}
      else
	my_putchar(number + '0');
    }
}

int	my_put_nbr(int nb)
{
  int	length;
  int	number;
  int	nb_max;

  length = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
	{
	  nb_max = 1;
	  nb = nb + 1;
	}
      nb = -nb;
    }
  number = nb;
  while (number > 10)
    {
      number = number / 10;
      length = length + 1;
    }
  if (number == 10)
    length = length + 1;
  display_nbr(nb, length, nb_max);
}
