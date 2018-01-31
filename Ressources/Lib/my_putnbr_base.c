/*
** my_putnbr_base.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:57:36 2014 Antoine Buchser
** Last update Thu Mar 20 18:05:27 2014 Antoine Buchser
*/

#include "mini.h"

void	my_put_zeros(int nbr)
{
  if (nbr == 0)
    my_putstr("00");
  else if (nbr < 16)
    my_putchar('0');
}

void	my_putnbr_base(long nbr, char *base)
{
  int	result[10];
  int	i;
  int	baselen;

  if (nbr < 0)
    my_putchar('-');
  nbr = (nbr < 0) ? -nbr : nbr;
  if (my_strcmp("0123456789abcdef", base) == 0
      || my_strcmp("0123456789ABCDEF", base) == 0)
    my_put_zeros(nbr);
  baselen = my_strlen(base);
  while (nbr != 0)
    {
      result[i] = nbr % baselen;
      nbr = nbr / baselen;
      i++;
    }
  while (--i >= 0)
    my_putchar(base[result[i]]);
}
