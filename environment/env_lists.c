/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:33:30 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include "../my.h"
#include "../mysh.h"

int	env_put_in_list(t_env **list, char *name, char *value)
{
  t_env	*elem;
  t_env	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (my_perror(NULL));
  elem->name = name;
  elem->value = value;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
  return (0);
}

t_env	*env_rm_from_list(t_env *list, char *name)
{
  t_env	*tmp;
  t_env	*rm_elem;
  int	found;

  if (list != NULL && my_strcmp(list->name, name) == 0)
    return (list->next);
  tmp = list;
  found = 0;
  while (tmp != NULL && tmp->next != NULL && found == 0)
    {
      if (my_strcmp(tmp->next->name, name) == 0)
	{
	  found = 1;
	  rm_elem = tmp->next;
	  if (tmp->next->next != NULL)
	    tmp->next = tmp->next->next;
	  else
	    tmp->next = NULL;
	  if (rm_elem != NULL)
	    free_one_list_elem(rm_elem);
	}
      tmp = tmp->next;
    }
  return (list);
}

char	*env_get_value_from_list(t_env *list, char *name)
{
  t_env	*tmp;
  int	found;

  tmp = list;
  found = 0;
  while (tmp != NULL && found == 0)
    {
      if (my_strcmp(tmp->name, name) == 0)
	{
	  found = 1;
	  return (tmp->value);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

void	env_change_value_in_list(t_env *list, char *name, char *new_value)
{
  t_env	*tmp;
  int	found;

  tmp = list;
  found = 0;
  while (tmp != NULL && found == 0)
    {
      if (tmp->name && my_strcmp(tmp->name, name) == 0)
	{
	  found = 1;
	  if (tmp->value)
	    free(tmp->value);
	  tmp->value = (new_value) ? my_strdup(new_value) : NULL;
	}
      tmp = tmp->next;
    }
}

void	env_show_list(t_env *list, char separator)
{
  t_env	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->name);
      my_putchar('=');
      if (tmp->value != NULL)
	my_putstr(tmp->value);
      my_putchar(separator);
      tmp = tmp->next;
    }
}
