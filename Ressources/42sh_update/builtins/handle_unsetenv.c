/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:48:58 2014 Hugo Schoch
*/

#include <stdio.h>
#include "../include/mysh.h"
#include "../include/myprintf.h"

void	handle_unsetenv(t_sh *sh, t_cl *tmp)
{
  if (tmp->cl[1] != NULL)
    {
      sh->env_list = env_rm_from_list(sh->env_list, tmp->cl[1]);
      free_wordtab(sh->env_tab);
      sh->env_tab = env_list_to_tab(sh->env_list);
      free_wordtab(sh->path_tab);
      sh->path_tab = path_to_tab(sh->env_list);
    }
  else
    my_putstr("unsetenv: Too few arguments.\n");
}
