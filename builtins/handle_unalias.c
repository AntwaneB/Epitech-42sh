/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 14:03:49 2014 François KIENE
*/

#include "../my.h"
#include "../mysh.h"

int	handle_unalias(t_sh *sh, t_cl *tmp)
{
  int	i;

  if (tmp->cl && tmp->cl[1] && !my_strcmp(tmp->cl[1], "-a"))
    ali_free_everything(&(sh->alias_list));
  else if (tmp->cl && tmp->cl[1])
    {
      i = 1;
      while (tmp->cl && tmp->cl[i])
	{
	  if (ali_exists(sh->alias_list, tmp->cl[i]))
	    ali_remove(&(sh->alias_list), tmp->cl[i]);
	  else
	    my_printf("unalias: %s: not found\n", tmp->cl[i]);
	  i++;
	}
    }
  else
    my_putstr("unalias: usage: unalias [-a] name [name ...]\n");
  return (0);
}
