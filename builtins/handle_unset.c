/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 14:04:24 2014 François KIENE
*/

#include "../mysh.h"

int	handle_unset(t_sh *sh, t_cl *tmp)
{
  int	i;

  i = 1;
  while (tmp->cl && tmp->cl[i])
    {
      if (var_exists(sh->var_list, tmp->cl[i]))
	var_remove(&(sh->var_list), tmp->cl[i]);
      i++;
    }
  return (0);
}
