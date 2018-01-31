/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:44:25 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

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

void	var_free_everything(t_var **list)
{
  t_var	*tmp;
  t_var	*rm;

  tmp = *list;
  while (tmp)
    {
      rm = tmp;
      tmp = tmp->next;
      free(rm->name);
      free(rm->value);
      free(rm);
    }
  *list = NULL;
}
