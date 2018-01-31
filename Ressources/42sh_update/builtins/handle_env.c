/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:51:03 2014 Hugo Schoch
*/

#include <stdio.h>
#include "../include/mysh.h"
#include "../include/mystr.h"
#include "../include/myprintf.h"

void	handle_env(t_sh *sh, t_cl *tmp)
{
  if (tmp->cl[1] == NULL)
    env_show_list(sh->env_list, '\n');
  else if (my_strcmp(tmp->cl[1], "-0") == 0)
    env_show_list(sh->env_list, '\0');
  else if (my_strcmp(tmp->cl[1], "-u") == 0)
    {
      if (tmp->cl[2] != NULL)
	{
	  sh->env_list = env_rm_from_list(sh->env_list, tmp->cl[2]);
	  free_wordtab(sh->env_tab);
	  sh->env_tab = env_list_to_tab(sh->env_list);
	  free_wordtab(sh->path_tab);
	  sh->path_tab = path_to_tab(sh->env_list);
	}
      else
	my_putstr("env -u: Too few arguments.\n");
    }
  else
    my_printf("env: invalid option -- '%s'\n", tmp->cl[1]);
}
