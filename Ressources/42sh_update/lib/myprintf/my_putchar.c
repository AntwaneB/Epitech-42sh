/*
** my_putchar.c for my_putchar in /home/schoch_h/Piscine/Piscine-C-lib/my
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Tue Oct  8 09:32:54 2013 SCHOCH Hugo
** Last update Thu May  8 14:20:34 2014 Hugo Schoch
*/

#include "../../include/myprintf.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}
