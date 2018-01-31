/*
** my_power_rec.c for my_power_rec in /home/schoch_h/Piscine/Piscine-C-Jour_05
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Sun Oct  6 16:20:22 2013 SCHOCH Hugo
** Last update Thu May  8 22:08:21 2014 Hugo Schoch
*/

#include "../../include/mynbr.h"

static int	calc_power(int nb, int power, int result)
{
  if (power > 0)
    {
      result = result * nb;
      power = power - 1;
      calc_power(nb, power, result);
    }
  else
    return (result);
}

int	my_pow(int nb, int power)
{
  if (power > 0)
    return (calc_power(nb, power, 1));
  else
    return (0);
}
