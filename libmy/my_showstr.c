/*
** my_showstr.c for my_showstr in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Oct  8 09:49:40 2013 Antoine Buchser
** Last update Fri May 16 11:35:04 2014 Thomas MORITZ
*/

#include "my.h"

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 32 && str[i] <= 126)
	my_putchar(str[i]);
      else if (str[i] == '"' && str[i + 1] == '"')
	i++;
      else
	{
	  my_putchar('\\');
	  my_put_nbr(0);
	  my_putnbr_base((str[i]), "0123456789abcdef");
	}
      i = i + 1;
    }
  return (0);
}
