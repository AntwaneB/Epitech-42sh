/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:57:47 2014 François KIENE
*/

#include "../mysh.h"

int	handle_history(t_sh *sh, t_cl *tmp)
{
  print_history(&(sh->history));
  return (0);
}
