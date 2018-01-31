/*
** exec_echo.c for 42 in /home/thomas/Projets/42sh
** 
** Made by Thomas MORITZ
** Login   <moritz_t@epitech.eu>
** 
** Started on  Wed Apr 23 10:39:30 2014 Thomas MORITZ
** Last update Thu May  8 21:55:18 2014 Hugo Schoch
*/

#include <stdio.h>
#include "../include/mysh.h"
#include "../include/mystr.h"
#include "../include/myprintf.h"

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

void	put_specstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\\')
	{
	  i = i + 1;
	  show_specchar(str[i]);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}

int	handle_specific_options(t_sh *sh, t_cl *tmp, int i)
{
  if (tmp->cl && tmp->cl[1]
      && my_strcmp(tmp->cl[1], "-e") == 0)
    {
      while (tmp->cl[i])
	{
	  put_specstr(tmp->cl[i++]);
	  my_putchar(' ');
	}
      my_putchar('\n');
      return (1);
    }
  else if (tmp->cl && tmp->cl[1]
	   && my_strcmp(tmp->cl[1], "-E") == 0)
    {
      while (tmp->cl[i])
	{
	  my_showstr(tmp->cl[i++]);
	  my_putchar(' ');
	}
      my_putchar('\n');
      return (1);
    }
  else
    handle_simplecase(sh, tmp);
  return (0);
}

int	handle_simplecase(t_sh *sh, t_cl *tmp)
{
  int	i;

  i = 1;
  while (tmp->cl[i])
    {
      my_showstr(tmp->cl[i++]);
      my_putchar(' ');
    }
  my_putchar('\n');
  return (1);
}

int	handle_echo(t_sh *sh, t_cl *tmp)
{
  int	i;

  i = 0;
  while (tmp->cl[i])
    i++;
  if (tmp->cl && tmp->cl[1]
      && ((my_strcmp(tmp->cl[1], "-n") == 0 && i == 2)
	  || (my_strcmp(tmp->cl[1], "-e") == 0 && i == 2)
	  || (my_strcmp(tmp->cl[1], "-E") == 0 && i == 2)))
    return (0);
  i = 2;
  if (tmp->cl && tmp->cl[1] && my_strcmp(tmp->cl[1], "-n") == 0)
    {
      while (tmp->cl[i])
	my_showstr(tmp->cl[i++]);
      return (1);
    }
  else
    handle_specific_options(sh, tmp, i);
  return (1);
}
