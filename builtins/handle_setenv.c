/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 14:02:16 2014 François KIENE
*/

#include "../my.h"
#include "../mysh.h"

static int	is_value_already_in_env(t_env *list, char *name)
{
  t_env		*tmp;
  int		found;

  found = 0;
  tmp = list;
  while (tmp != NULL && found == 0)
    {
      if (my_strcmp(tmp->name, name) == 0)
	found = 1;
      tmp = tmp->next;
    }
  return (found);
}

int	handle_setenv(t_sh *sh, t_cl *tmp)
{
  char	*name;
  char	*value;

  if (tmp->cl[1] != NULL)
    {
      name = my_strdup(tmp->cl[1]);
      if (tmp->cl[2] != NULL)
	value = my_strdup(tmp->cl[2]);
      else
	value = NULL;
      if (is_value_already_in_env(sh->env_list, name))
	sh->env_list = env_rm_from_list(sh->env_list, name);
      env_put_in_list(&(sh->env_list), name, value);
      free_wordtab(sh->env_tab);
      sh->env_tab = env_list_to_tab(sh->env_list);
      free_wordtab(sh->path_tab);
      sh->path_tab = path_to_tab(sh->env_list);
    }
  else
    env_show_list(sh->env_list, '\n');
  return (0);
}
