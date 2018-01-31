/*
** my_putnbr_base.c for my_putnbr_base in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Oct  7 17:06:27 2013 Antoine Buchser
** Last update Thu Apr 24 20:40:43 2014 Antoine Buchser
*/

#include "my.h"

int	my_putlongnbr_base(long long int nbr, char *base)
{
  if (nbr < 0)
    {
      nbr = -nbr;
      my_putchar('-');
    }
  if (nbr >= my_strlen(base) - 1)
    my_putlongnbr_base(nbr / my_strlen(base), base);
  my_putchar(base[nbr % my_strlen(base)]);
  return (0);
}
