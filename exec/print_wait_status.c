/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:25:30 2014 Thomas MORITZ
*/

#include <stdio.h>
#include <sys/wait.h>
#include "../mysh.h"

void	print_wait_status(t_sh *sh, int status)
{
  if (status && WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == 11)
	printf("Swègmentation fault (core dumped)\n");
    }
}
