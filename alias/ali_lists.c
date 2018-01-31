/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:10:03 2014 Antoine Buchser
*/

#include <stdlib.h>
#include "../my.h"
#include "../mysh.h"

int	ali_put_in_list(t_ali **list, char *name, char *value)
{
  t_ali	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->name = (name != NULL) ? my_strdup(name) : NULL;
  elem->value = (value != NULL) ? my_strdup(value) : NULL;
  elem->next = *list;
  *list = elem;
  return (0);
}

char	*ali_get_value(t_ali *list, char *name)
{
  t_ali	*tmp;
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
  return ((found && tmp->value) ? tmp->value : NULL);
}

static void	ali_free_one_list_elem(t_ali *tmp)
{
  if (tmp->name)
    free(tmp->name);
  if (tmp->value)
    free(tmp->value);
  if (tmp)
    free(tmp);
}

int	ali_remove(t_ali **list, char *name)
{
  t_ali	*tmp;
  t_ali	*rm_elem;
  int	found;

  found = 0;
  tmp = *list;
  if (tmp != NULL && my_strcmp(tmp->name, name) == 0)
    {
      *list = tmp->next;
      ali_free_one_list_elem(tmp);
      found = 1;
    }
  while (!found && tmp != NULL && tmp->next != NULL)
    {
      if (my_strcmp(tmp->next->name, name) == 0)
	{
	  found = 1;
	  rm_elem = tmp->next;
	  tmp->next = tmp->next->next;
	  if (rm_elem != NULL)
	    ali_free_one_list_elem(rm_elem);
	}
      tmp = tmp->next;
    }
  return (found);
}

int	ali_exists(t_ali *list, char *name)
{
  t_ali	*tmp;
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
