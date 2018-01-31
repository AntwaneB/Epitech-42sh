/*
** my_getnbr.c for my_getnbr in /home/schoch_h/Piscine/Piscine-C-Jour_04
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Fri Oct  4 11:19:04 2013 SCHOCH Hugo
** Last update Thu May  8 22:08:08 2014 Hugo Schoch
*/

#include "../../include/mynbr.h"

static int	chk_digit(char digit)
{
  if (digit >= '0' && digit <= '9')
    return (digit - '0');
  return ('a');
}

static int	islimit(int number, int nxt, int negatif)
{
  int		rep;

  rep = number;
  if (number >= 214748364 && nxt > 7 && nxt != 'a' && !negatif)
    rep = 0;
  if (number >= 214748364 && nxt > 8 && nxt != 'a' && negatif)
    rep = 0;
  return (rep);
}

int	my_getnbr(char *str)
{
  int	position;
  int	neg;
  int	nbr;
  int	stop;
  int	digit;

  position = 0;
  nbr = 0;
  stop = 0;
  neg = 0;
  while (str[position] && (stop >= 0))
    {
      if (str[position] == '-')
        neg = (neg + 1) % 2;
      digit = chk_digit(str[position]);
      if (digit <= 9 && digit >= 0)
        {
          nbr = islimit((nbr * 10) + digit, chk_digit(str[position + 1]), neg);
	  if (nbr == 0)
	    stop = -2;
        }
      stop = stop + 1;
      position = position + 1;
    }
  return ((neg) ? -nbr : nbr);
}
