/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:43:32 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

int	var_put_in_list(t_var **list, char *name, char *value)
{
  t_var	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->name = (name != NULL) ? my_strdup(name) : NULL;
  elem->value = (value != NULL) ? my_strdup(value) : NULL;
  elem->next = *list;
  *list = elem;
  return (0);
}

char	*var_get_value(t_var *list, char *name)
{
  t_var	*tmp;
  int	found;

  found = 0;
  tmp = list;
  while (tmp && !found)
    {
      if (tmp->name && !my_strcmp(name, tmp->name))
	found = 1;
      else
	tmp = tmp->next;
    }
  return ((found) ? tmp->value : NULL);
}

int	var_exists(t_var *list, char *name)
{
  t_var	*tmp;
  int	found;

  found = 0;
  tmp = list;
  while (tmp && !found)
    {
      if (tmp->name && !my_strcmp(tmp->name, name))
	found = 1;
      else
	tmp = tmp->next;
    }
  return (found);
}
