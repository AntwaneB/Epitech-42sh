/*
** exec_echo.c for 42 in /home/thomas/Projets/42sh
** 
** Made by Thomas MORITZ
** Login   <moritz_t@epitech.eu>
** 
** Started on  Wed Apr 23 10:39:30 2014 Thomas MORITZ
** Last update Sat May 24 13:55:16 2014 François KIENE
*/

#include "../my.h"
#include "../mysh.h"

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
      else if (str[i] == '"' && str[i + 1] == '"')
	i++;
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
	  if (tmp->cl[i] != NULL)
	    my_putchar(' ');
	}
      my_putchar('\n');
      return (1);
    }
  else if (tmp->cl && tmp->cl[1]
	   && my_strcmp(tmp->cl[1], "-E") == 0)
    handle_second_option(sh, tmp, i);
  else
    handle_simplecase(sh, tmp);
  return (0);
}

int	handle_second_option(t_sh *sh, t_cl *tmp, int i)
{
  while (tmp->cl[i])
    {
      my_showstr(tmp->cl[i++]);
      if (tmp->cl[i] != NULL)
	my_putchar(' ');
    }
  my_putchar('\n');
  return (1);
}

int	handle_simplecase(t_sh *sh, t_cl *tmp)
{
  int	i;

  i = 1;
  while (tmp->cl[i])
    {
      my_showstr(tmp->cl[i++]);
      if (tmp->cl[i] != NULL)
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
