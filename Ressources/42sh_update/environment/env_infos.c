/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 22:01:44 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/mysh.h"
#include "../include/mystr.h"
#include "../include/myprintf.h"

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

void	env_show_list(t_env *list, char separator)
{
  t_env	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->value != NULL)
	my_printf("%s=%s%c", tmp->name, tmp->value, separator);
      else
	my_printf("%s=(null)%c", tmp->name, separator);
      tmp = tmp->next;
    }
}
