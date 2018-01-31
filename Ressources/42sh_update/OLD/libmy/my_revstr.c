/*
** my_revstr.c for my_revstr in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Oct  3 10:08:26 2013 Antoine Buchser
** Last update Thu Apr 24 20:43:45 2014 Antoine Buchser
*/

#include "my.h"

char	my_char_swap(char *a, char *b)
{
  char	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}

char	*my_revstr(char *str)
{
  int	i;
  int	strlen;

  strlen = my_strlen(str) - 1;
  i = 0;
  while (i < strlen - (strlen / 2))
    {
      my_char_swap(&str[i], &str[strlen - i]);
      i = i + 1;
    }
  return (str);
}
