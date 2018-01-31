/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:46:26 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include "../mysh.h"

static void	free_one_elem(t_cl *tmp)
{
  int		i;
  char		**wordtab;

  free(tmp->separator);
  wordtab = tmp->cl;
  i = 0;
  while (wordtab != NULL && wordtab[i] != NULL)
    {
      free(wordtab[i]);
      i++;
    }
  free(wordtab);
}

void	cl_free(t_clm *list)
{
  t_cl	*tmp;
  t_cl	*rm_elem;

  tmp = list->first;
  while (tmp != NULL)
    {
      free_one_elem(tmp);
      rm_elem = tmp;
      tmp = tmp->next;
      free(rm_elem);
    }
  list->first = NULL;
  list->last = NULL;
}
