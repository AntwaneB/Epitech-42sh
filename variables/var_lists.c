/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Wed May 21 12:52:24 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include "../my.h"
#include "../mysh.h"

int	var_put_in_list(t_var **list, char *name, char *value)
{
  t_var	*elem;

  if (var_exists(*list, name))
    var_remove(list, name);
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

static void	var_free_one_list_elem(t_var *tmp)
{
  if (tmp->name)
    free(tmp->name);
  if (tmp->value)
    free(tmp->value);
  if (tmp)
    free(tmp);
}

int	var_remove(t_var **list, char *name)
{
  t_var	*tmp;
  t_var	*rm_elem;
  int	found;

  found = 0;
  tmp = *list;
  if (tmp != NULL && my_strcmp(tmp->name, name) == 0)
    {
      *list = tmp->next;
      var_free_one_list_elem(tmp);
      found = 1;
    }
  while (!found && tmp && tmp->next)
    {
      if (my_strcmp(tmp->next->name, name) == 0)
        {
	  found = 1;
	  rm_elem = tmp->next;
	  tmp->next = tmp->next->next;
	  if (rm_elem != NULL)
	    var_free_one_list_elem(rm_elem);
        }
      tmp = tmp->next;
    }
  return (found);
}
