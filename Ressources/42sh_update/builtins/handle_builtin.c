/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:47:44 2014 Hugo Schoch
*/

#include "../include/mysh.h"
#include "../include/mystr.h"

int	handle_builtin(t_sh *sh, t_cl *tmp)
{
  if (tmp && tmp->cl && tmp->cl[0])
    {
      if (my_strcmp(tmp->cl[0], "cd") == 0)
	handle_cd(sh, tmp);
      else if (my_strcmp(tmp->cl[0], "setenv") == 0)
	handle_setenv(sh, tmp);
      else if (my_strcmp(tmp->cl[0], "unsetenv") == 0)
	handle_unsetenv(sh, tmp);
      else if (my_strcmp(tmp->cl[0], "env") == 0)
	handle_env(sh, tmp);
      else if (my_strcmp(tmp->cl[0], "exit") == 0)
	return (handle_exit(sh, tmp));
      else if (my_strcmp(tmp->cl[0], "alias") == 0)
	handle_alias(sh, tmp);
      else if (my_strcmp(tmp->cl[0], "unalias") == 0)
	handle_unalias(sh, tmp);
      else if (my_strcmp(tmp->cl[0], "echo") == 0)
	handle_echo(sh, tmp);
      else if (my_strcmp(tmp->cl[0], "unset") == 0)
	handle_unset(sh, tmp);
    }
  return (0);
}
