/*
** my_putnbr_base.c for my_putnbr_base in /home/schoch_h/Lib
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Thu Nov  7 23:26:08 2013 SCHOCH Hugo
** Last update Fri May  9 23:25:30 2014 Hugo Schoch
*/

#include "../../include/myprintf.h"

int     my_putnbr_base(int nbr, char *base)
{
  if (nbr < 0)
    {
      nbr = nbr * -1;
      my_putchar('-');
    }
  if (nbr >= my_strlen(base))
    my_putnbr_base(nbr / my_strlen_printf(base), base);
  my_putchar(base[nbr % my_strlen_printf(base)]);
  return (nbr);
}
