/*
** my_strlen.c for my_strlen in /home/schoch_h/Piscine/Piscine-C-Jour_04
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Thu Oct  3 11:18:37 2013 SCHOCH Hugo
** Last update Fri May  9 23:23:52 2014 Hugo Schoch
*/

#include <stdlib.h>
#include "../../include/myprintf.h"

int	my_tab_strlen_printf(char **tab)
{
  int	size;

  size = 0;
  while (tab[size] != NULL && tab[size] != '\0')
    size++;
  return (size);
}

int	my_strlen_printf(char *str)
{
  int	length;

  length = 0;
  while (str[length] != '\0')
    {
      length = length + 1;
    }
  return (length);
}
