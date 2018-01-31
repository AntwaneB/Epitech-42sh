/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:49:21 2014 Thomas MORITZ
*/

#include "../mysh.h"

int	cl_handle(t_sh *sh, t_clm *cl)
{
  if (cl && cl->first)
    {
      if (glob_handle(cl))
	return (-1);
      if (is_variable(sh, cl->first))
	var_create_handle(sh, cl->first);
      else
	{
	  if (is_builtin(sh, cl->first) != -1)
	    return (execute_cmd(sh));
	}
    }
  return (0);
}
