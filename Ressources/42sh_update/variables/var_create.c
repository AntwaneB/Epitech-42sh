/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:45:57 2014 Hugo Schoch
*/

#include <stdlib.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

int	var_create_handle(t_sh *sh, t_cl *tmp)
{
  int	i;

  i = -1;
  while (tmp && tmp->cl && tmp->cl[++i]);
  if (i == 3 && !my_strcmp(tmp->cl[1], "="))
    {
      if (!env_var_exists(sh->env_list, tmp->cl[0]))
	var_put_in_list(&(sh->var_list), tmp->cl[0], tmp->cl[2]);
      else
	{
	  sh->env_list = env_rm_from_list(sh->env_list, tmp->cl[0]);
	  env_put_in_list(&(sh->env_list), tmp->cl[0], tmp->cl[2]);
	}
      return (0);
    }
  return (-1);
}
