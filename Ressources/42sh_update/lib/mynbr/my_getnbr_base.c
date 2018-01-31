/*
** my_getnbr_base.c for my_getnbr_base in /home/schoch_h/Lib
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Thu Nov  7 23:14:42 2013 SCHOCH Hugo
** Last update Thu May  8 22:08:12 2014 Hugo Schoch
*/

#include "../../include/mynbr.h"

static int	check_neg(char *str)
{
  int		pos;
  int		neg;

  pos = 0;
  neg = 0;
  while (str[pos] != '\0' && (str[pos] < '0' || str[pos] > '9'))
    {
      if (str[pos] == '-')
	neg++;
      pos++;
    }
  if (neg % 2 == 0)
    return (1);
  return (-1);
}

static int	check_base(char *base)
{
  int		pos;
  int		n;

  n = 0;
  while (base[n])
    {
      pos = 0;
      while (base[pos])
        {
          if (pos != n && base[n] == base[pos])
	    return (-1);
	  pos++;
        }
      n++;
    }
  return (0);
}

static int	base_len(char *str)
{
  int	length;

  length = 0;
  while (str[length] != '\0')
    length++;
  return (length);
}

int     my_getnbr_base(char *str, char *base)
{
  int   nbr;
  int   length;
  int   pos;
  int   pos_base;
  int   neg;

  pos = 0;
  neg = 1;
  length = base_len(base);
  neg = check_neg(str);
  if (check_base(base) == -1)
    return (0);
  while (str[pos])
    {
      pos_base = 0;
      while (pos_base < length && base[pos_base] != str[pos])
        pos_base = pos_base + 1;
      if (base[pos_base] == str[pos])
        nbr = nbr * length + pos_base;
      else if ((str[pos] != '-' && str[pos] != '+'))
	return (0);
      pos = pos + 1;
    }
  return (nbr * neg);
}
