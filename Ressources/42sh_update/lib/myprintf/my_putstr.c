/*
** my_putstr.c for my_putstr in /home/schoch_h/Piscine/Piscine-C-Jour_04
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Thu Oct  3 14:15:36 2013 SCHOCH Hugo
** Last update Fri May  9 23:26:06 2014 Hugo Schoch
*/

#include "../../include/myprintf.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen_printf(str));
}
