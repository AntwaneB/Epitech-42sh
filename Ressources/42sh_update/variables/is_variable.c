/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:45:20 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

int	is_variable(t_sh *sh, t_cl *cl)
{
  int	i;

  i = -1;
  while (cl && cl->cl[++i]);
  if (i == 3 && !my_strcmp(cl->cl[1], "="))
    return (1);
  else
    return (0);
}
