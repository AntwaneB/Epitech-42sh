/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:52:23 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include "../mysh.h"

int	cl_put_in_list(t_clm *list, char **cl, char *sep)
{
  t_cl	*elem;

  if (cl && cl[0])
    {
      if ((elem = malloc(sizeof(t_cl))) == NULL)
	return (my_perror(NULL));
      elem->next = NULL;
      elem->prev = list->last;
      elem->cl = cl;
      elem->writeto = NULL;
      elem->readfrom = NULL;
      elem->env = 1;
      elem->separator = sep;
      if (list->last != NULL)
	list->last->next = elem;
      list->last = elem;
      if (list->first == NULL)
	list->first = elem;
    }
  return (0);
}
