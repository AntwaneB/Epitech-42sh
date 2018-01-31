/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/buchse_a/Documents/Piscine-C-Jour_08/ex_04
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Wed Oct  9 11:01:05 2013 Antoine Buchser
** Last update Thu Apr 24 20:45:32 2014 Antoine Buchser
*/

#include <stdlib.h>
#include "my.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
