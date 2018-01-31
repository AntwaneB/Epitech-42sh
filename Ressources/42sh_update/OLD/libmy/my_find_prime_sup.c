/*
** my_find_prime_sup.c for my_find_prime_sup in /home/buchse_a/Documents/Piscine-C-Jour_05
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Fri Oct  4 16:43:00 2013 Antoine Buchser
** Last update Thu Apr 24 20:28:46 2014 Antoine Buchser
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  if (my_is_prime(nb) == 1)
    return (nb);
  else
    {
      if (nb % 2 == 0)
	nb = nb + 1;
      while (my_is_prime(nb) != 1)
	nb = nb + 2;
      return (nb);
    }
}
