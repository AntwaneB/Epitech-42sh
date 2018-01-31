/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 22:06:39 2014 Hugo Schoch
*/

#include <stdio.h>
#include "../include/mysh.h"
#include "../include/mynbr.h"

int	handle_exit(t_sh *sh, t_cl *tmp)
{
  env_list_free(sh->env_list);
  free_wordtab(sh->env_tab);
  free_wordtab(sh->path_tab);
  ali_free_everything(&(sh->alias_list));
  var_free_everything(&(sh->var_list));
  if (sh->env_list)
    my_reset();
  if (tmp->cl[1])
    return (my_getnbr(tmp->cl[1]));
  return (-1);
}
