/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:31:36 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include "../my.h"
#include "../mysh.h"

int	env_list_size(t_env *env_list)
{
  t_env	*tmp;
  int	i;

  i = 0;
  tmp = env_list;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

void	env_list_free(t_env *env_list)
{
  t_env	*tmp;
  t_env	*rm;

  tmp = NULL;
  if (env_list != NULL && env_list->next != NULL)
    tmp = env_list->next;
  if (env_list != NULL)
    {
      free(env_list->name);
      if (env_list->value != NULL)
	free(env_list->value);
      free(env_list);
    }
  while (tmp != NULL)
    {
      rm = tmp;
      tmp = tmp->next;
      if (rm->name)
	free(rm->name);
      if (rm->value != NULL)
	free(rm->value);
      free(rm);
    }
}

void	free_one_list_elem(t_env *tmp)
{
  free(tmp->name);
  free(tmp->value);
  free(tmp);
}

int	env_var_exists(t_env *env_list, char *name)
{
  t_env	*tmp;
  int	found;

  found = 0;
  tmp = env_list;
  while (tmp && !found)
    {
      if (!my_strcmp(tmp->name, name))
	found = 1;
      else
	tmp = tmp->next;
    }
  return (found);
}

int	env_change_and_update(t_sh *sh, char *name, char *value)
{
  char	*newvalue;
  char	*newname;

  if (env_var_exists(sh->env_list, name))
    env_change_value_in_list(sh->env_list, name, value);
  else
    {
      newname = (name) ? my_strdup(name) : NULL;
      newvalue = (value) ? my_strdup(value) : NULL;
      env_put_in_list(&(sh->env_list), newname, newvalue);
    }
  free_wordtab(sh->env_tab);
  sh->env_tab = env_list_to_tab(sh->env_list);
  free_wordtab(sh->path_tab);
  sh->path_tab = path_to_tab(sh->env_list);
  return (0);
}
