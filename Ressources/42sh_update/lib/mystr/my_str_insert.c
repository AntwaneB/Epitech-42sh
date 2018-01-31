/*
** my_str_insert.c for my_str_insert in /home/schoch_h/Lib
** 
** Made by Hugo Schoch
** Login   <schoch_h@epitech.net>
** 
** Started on  Thu May  1 00:46:54 2014 Hugo Schoch
** Last update Thu May  8 14:37:47 2014 Hugo Schoch
*/

#include <stdlib.h>
#include "../../include/mystr.h"

char	*my_str_insert(char *str, int pos, char *insert)
{
  char	*res;
  char	*end;
  int	pos_cpy;

  pos_cpy = 0;
  res = my_strdup(str);
  res[pos + 1] = '\0';
  res = my_strcat(res, insert);
  if ((end = malloc((my_strlen(str) - pos) * sizeof(*end))) == NULL)
    return (NULL);
  pos++;
  while (str[pos] != '\0')
    {
      end[pos_cpy] = str[pos];
      pos++;
      pos_cpy++;
    }
  end[pos_cpy] = '\0';
  res = my_strcat(res, end);
  return (res);
}
