/*
** my_putchar.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:13:39 2014 Antoine Buchser
** Last update Thu Mar 20 17:31:21 2014 Antoine Buchser
*/

#include <unistd.h>
#include "mini.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
