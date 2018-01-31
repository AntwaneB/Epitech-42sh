/*
** my_put_nbr_rec.c for my_put_nbr in /home/buchse_a/Documents/Piscine-C-Jour_03
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Sun Oct  6 13:37:49 2013 Antoine Buchser
** Last update Sat May 24 13:19:57 2014 François KIENE
*/

#include "my.h"

int	my_put_unnbr_rec(unsigned int nb, int tmp, int power)
{
  if (power> 0)
    {
      tmp = ((nb / power) % 10);
      tmp = tmp + '0';
      my_putchar(tmp);
      my_put_unnbr_rec(nb, 0, (power/ 10));
    }
  return (0);
}

int	my_put_unnbr(unsigned int nb)
{
  int	power;

  power = 1;
  while ((nb / power) >= 10)
    power = power* 10;
  my_put_unnbr_rec(nb, 0, power);
  return (0);
}
