/*
** my_show_wordtab.c for my_show_wordtab in /home/schoch_h/Piscine/Piscine-C-Jour_08/ex_05
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Thu Oct 10 17:43:36 2013 SCHOCH Hugo
** Last update Fri May  9 23:27:51 2014 Hugo Schoch
*/

#include <stdlib.h>
#include "../../include/myprintf.h"

void	my_show_wordtab(char **tab)
{
  int	length;
  int	word;

  length = my_tab_strlen_printf(tab);
  word = 0;
  while (tab[word] != NULL)
    {
      if (word)
	my_putchar('\n');
      my_printf("%s",tab[word]);
      word = word + 1;
    }
}

void	my_show_wordtab_octal(char **tab)
{
  int	length;
  int	word;

  length = my_tab_strlen_printf(tab);
  word = 0;
  while (tab[word] != NULL)
    {
      if (word)
	my_putchar('\n');
      my_printf("%S",tab[word]);
      word = word + 1;
    }
}
