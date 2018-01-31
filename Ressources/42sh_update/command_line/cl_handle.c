/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 15:17:31 2014 Hugo Schoch
*/

#include "../include/mysh.h"

int	cl_handle(t_sh *sh, t_clm *cl)
{
  ali_handle(sh, cl);
  var_handle(sh, cl);
  if (is_builtin(sh, cl->first))
    return (handle_builtin(sh, cl->first));
  else if (is_variable(sh, cl->first))
    var_create_handle(sh, cl->first);
  else
    {
      if (is_builtin(sh, cl->first) != -1)
	my_execve(sh);
    }
  return (0);
}
