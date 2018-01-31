/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:29:21 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

int	count_pipes(t_clm *cl)
{
  int	count;
  t_cl	*tmp;

  count = 0;
  tmp = cl->first;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->separator, "|") == 0)
	count++;
      tmp = tmp->next;
    }
  return (count);
}
