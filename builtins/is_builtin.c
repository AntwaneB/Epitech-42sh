/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 14:04:52 2014 François KIENE
*/

#include "../my.h"
#include "../mysh.h"

int	is_builtin(t_sh *sh, t_cl *tmp)
{
  if (tmp != NULL && tmp->cl != NULL)
    {
      if (!my_strcmp(tmp->cl[0], "cd")
	  || !my_strcmp(tmp->cl[0], "setenv")
	  || !my_strcmp(tmp->cl[0], "unsetenv")
	  || !my_strcmp(tmp->cl[0], "env")
	  || !my_strcmp(tmp->cl[0], "exit")
	  || !my_strcmp(tmp->cl[0], "alias")
	  || !my_strcmp(tmp->cl[0], "unalias")
	  || !my_strcmp(tmp->cl[0], "echo")
	  || !my_strcmp(tmp->cl[0], "unset")
	  || !my_strcmp(tmp->cl[0], "history")
	  || !my_strcmp(tmp->cl[0], "set")
	  || !my_strcmp(tmp->cl[0], "unset"))
	return (1);
      else
	return (0);
    }
  else
    return (-1);
}
