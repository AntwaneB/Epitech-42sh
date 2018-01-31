/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 14:00:14 2014 François KIENE
*/

#include "../my.h"
#include "../mysh.h"

int	handle_set(t_sh *sh, t_cl *tmp)
{
  int	i;

  i = -1;
  while (tmp && tmp->cl && tmp->cl[++i]);
  if (i == 4 && !my_strcmp(tmp->cl[2], "="))
    {
      if (!env_var_exists(sh->env_list, tmp->cl[1]))
	var_put_in_list(&(sh->var_list), tmp->cl[1], tmp->cl[3]);
      else
	{
	  sh->env_list = env_rm_from_list(sh->env_list, tmp->cl[1]);
	  env_put_in_list(&(sh->env_list), my_strdup(tmp->cl[1]),
			  my_strdup(tmp->cl[3]));
	  free_wordtab(sh->env_tab);
	  sh->env_tab = env_list_to_tab(sh->env_list);
	  free_wordtab(sh->path_tab);
	  sh->path_tab = path_to_tab(sh->env_list);
	}
      return (0);
    }
  return (-1);
}
