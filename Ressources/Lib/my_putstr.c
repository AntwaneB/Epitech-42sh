/*
** my_putstr.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:31:47 2014 Antoine Buchser
** Last update Thu Mar 20 17:32:24 2014 Antoine Buchser
*/

#include <unistd.h>
#include "mini.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
