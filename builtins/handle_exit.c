/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:59:30 2014 François KIENE
*/

#include <stdlib.h>
#include "../my.h"
#include "../mysh.h"

int	handle_exit(t_sh *sh, t_cl *tmp)
{
  env_list_free(sh->env_list);
  free_wordtab(sh->env_tab);
  free_wordtab(sh->path_tab);
  ali_free_everything(&(sh->alias_list));
  var_free_everything(&(sh->var_list));
  hist_free(&(sh->history));
  if (sh->env_list)
    my_reset();
  sh->exit = 1;
  sh->exit_value = (tmp->cl[1]) ? my_getnbr(tmp->cl[1])
    : EXIT_SUCCESS;
  return (-1);
}
