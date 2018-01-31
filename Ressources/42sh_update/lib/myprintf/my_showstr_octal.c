/*
** my_showstr.c for my_showstr in /home/schoch_h/Piscine/Piscine-C-lib/my
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Tue Oct  8 13:49:03 2013 SCHOCH Hugo
** Last update Thu May  8 14:20:59 2014 Hugo Schoch
*/

#include "../../include/myprintf.h"

int	my_showstr_octal(char *str)
{
  int	pos;

  pos = 0;
  while (str[pos] != '\0')
    {
      if (str[pos] < 32 || str[pos] > 126)
	{
	  my_putchar(92);
	  if (str[pos] < 32)
	    my_putchar('0');
	  my_putnbr_base(str[pos], "01234567");
	}
      else
	my_putchar(str[pos]);
      pos = pos + 1;
    }
  return (0);
}
