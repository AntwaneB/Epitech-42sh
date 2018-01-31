/*
** my_putchar.c for my_putchar in /home/buchse_a/Documents/Piscine-C-Jour_03
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Wed Oct  2 13:00:47 2013 Antoine Buchser
** Last update Thu Apr 24 20:31:25 2014 Antoine Buchser
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
