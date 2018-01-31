/*
** my_putnbr.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:49:33 2014 Antoine Buchser
** Last update Thu Mar 20 17:56:31 2014 Antoine Buchser
*/

#include "mini.h"

void	my_putnbr(long nb)
{
  int	pow;

  if (nb < 0)
    my_putchar('-');
  nb = (nb < 0) ? -nb : nb;
  pow = 1;
  while ((nb / pow) >= 10)
    pow = pow * 10;
  while (pow > 0)
    {
      my_putchar(((nb / pow) % 10) + '0');
      pow = pow / 10;
    }
}
