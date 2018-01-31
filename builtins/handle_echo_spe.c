/*
** handle_echo_spe.c for 42 in /home/thomas/Projets/42sh/builtins
** 
** Made by Thomas MORITZ
** Login   <moritz_t@epitech.eu>
** 
** Started on  Wed May 21 12:55:53 2014 Thomas MORITZ
** Last update Wed May 21 12:57:31 2014 Thomas MORITZ
*/

#include "../my.h"

void	show_specchar(char c)
{
  if (c == '\\')
    my_putchar('\\');
  else if (c == 'a')
    my_putchar('\a');
  else if (c == 'b')
    my_putchar('\b');
  else if (c == 'e')
    my_putchar('\e');
  else if (c == 'f')
    my_putchar('\f');
  else if (c == 'n')
    my_putchar('\n');
  else if (c == 'r')
    my_putchar('\r');
  else if (c == 't')
    my_putchar('\t');
  else if (c == 'v')
    my_putchar('\v');
  else
    my_putchar(c);
}
