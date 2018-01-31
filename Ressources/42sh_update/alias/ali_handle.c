/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:00:19 2014 Hugo Schoch
*/

#include <stdio.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

static int	ali_replace_alias(t_sh *sh, char **cl,
				  char ***cl_ptr, int i)
{
  char		**insert;

  if (cl[i] && ali_exists(sh->alias_list, cl[i]))
    {
      insert = my_str_to_wordtab(ali_get_value(sh->alias_list, cl[i]));
      *cl_ptr = insert_wordtab_after_elem(cl, insert, i);
      free_wordtab(insert);
      free_wordtab(cl);
      return ((*cl_ptr == NULL) ? -1 : 0);
    }
  return (0);
}


int	ali_handle(t_sh *sh, t_clm *cl)
{
  t_cl	*tmp;

  tmp = cl->first;
  while (tmp)
    {
      if (tmp->cl && tmp->cl[0])
	ali_replace_alias(sh, tmp->cl, &(tmp->cl), 0);
      tmp = tmp->next;
    }
  return (0);
}
