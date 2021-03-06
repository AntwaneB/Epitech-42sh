/*
** my_putnbr_base.c for my_putnbr_base in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Oct  7 17:06:27 2013 Antoine Buchser
** Last update Thu Apr 24 20:53:14 2014 Antoine Buchser
*/

#include "my.h"

int	my_putunnbr_base(unsigned long nbr, char *base)
{
  int	result[10];
  int	i;

  i = 0;
  if (!my_strcmp(base, "0123456789abcdef")
      || !my_strcmp(base, "0123456789ABCDEF"))
    my_put_zeros(nbr);
  while (nbr != 0)
    {
      result[i] = nbr % my_strlen(base);
      nbr = nbr / my_strlen(base);
      i = i + 1;
    }
  i = i - 1;
  while (i >= 0)
    {
      my_putchar(base[result[i]]);
      i = i - 1;
    }
  return (0);
}
