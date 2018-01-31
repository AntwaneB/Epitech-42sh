/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:47:13 2014 Hugo Schoch
*/

#include <stdio.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

int	is_builtin(t_sh *sh, t_cl *tmp)
{
  if (tmp != NULL && tmp->cl != NULL)
    {
      if (my_strcmp(tmp->cl[0], "cd") == 0)
	return (1);
      else if (my_strcmp(tmp->cl[0], "setenv") == 0)
	return (1);
      else if (my_strcmp(tmp->cl[0], "unsetenv") == 0)
	return (1);
      else if (my_strcmp(tmp->cl[0], "env") == 0)
	return (1);
      else if (my_strcmp(tmp->cl[0], "exit") == 0)
	return (1);
      else if (my_strcmp(tmp->cl[0], "alias") == 0)
	return (1);
      else if (my_strcmp(tmp->cl[0], "unalias") == 0)
	return (1);
      else if (my_strcmp(tmp->cl[0], "echo") == 0)
	return (1);
      else if (my_strcmp(tmp->cl[0], "unset") == 0)
	return (1);
      else
	return (0);
    }
  else
    return (-1);
}
