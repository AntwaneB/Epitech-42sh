/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:31:41 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/mysh.h"

void	print_wait_status(t_sh *sh, int status)
{
  if (status && WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == 11)
	printf("Swègmentation fault (core dumped)\n");
      else if (WTERMSIG(status) != 2)
	printf("Program exited after receiving signal %d.\n",
	       WTERMSIG(status));
    }
}
