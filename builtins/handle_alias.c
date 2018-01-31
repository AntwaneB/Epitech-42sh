/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:50:35 2014 François KIENE
*/

#include "../my.h"
#include "../mysh.h"

static void	exec_create_alias(t_sh *sh, t_cl *tmp, int i)
{
  ali_remove(&(sh->alias_list), tmp->cl[1]);
  ali_put_in_list(&(sh->alias_list), tmp->cl[1], tmp->cl[3]);
}

int	handle_alias(t_sh *sh, t_cl *tmp)
{
  int	i;
  char	*value;

  i = -1;
  while (tmp->cl[++i]);
  if (i == 4 && !my_strcmp(tmp->cl[2], "="))
    exec_create_alias(sh, tmp, i);
  else if (i == 2)
    {
      if (ali_exists(sh->alias_list, tmp->cl[1]))
	{
	  value = ali_get_value(sh->alias_list, tmp->cl[1]);
	  if (value)
	    my_printf("alias %s='%s'\n", tmp->cl[1], value);
	}
      else
	{
	  my_printf("alias: %s: not found\n", tmp->cl[1]);
	  return (-1);
	}
    }
  return (0);
}
