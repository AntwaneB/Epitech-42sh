/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Wed May 21 12:51:25 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include "../my.h"
#include "../mysh.h"

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
