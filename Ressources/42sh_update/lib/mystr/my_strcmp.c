/*
** my_strcmp.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:33:31 2014 Antoine Buchser
** Last update Fri May  9 23:18:29 2014 Hugo Schoch
*/

#include "../../include/mystr.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	check;

  check = 1;
  i = 0;
  while (i < my_strlen(s1) && i < my_strlen(s1) && check == 1)
    {
      check = (s1[i] == s2[i]) ? 1 : 0;
      i++;
    }
  if (check == 1 && my_strlen(s1) == my_strlen(s2))
    return (0);
  else if (check == 1 && my_strlen(s1) < my_strlen(s2))
    return (s2[i - 1]);
  else if (check == 1 && my_strlen(s1) > my_strlen(s2))
    return (s1[i - 1]);
  else
    return (s1[i - 1] - s2[i - 1]);
}
