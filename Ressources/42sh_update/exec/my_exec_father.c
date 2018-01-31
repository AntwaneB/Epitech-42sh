/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:27:18 2014 Hugo Schoch
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
#include "../include/mystr.h"

int	proceed_father(t_sh *sh, int *pipefds,
		       t_cl **tmp, t_pid *pi)
{
  int	status;

  //  kill(pi->pid, SIGKILL);
  if ((waitpid(pi->pid, &status, 0)) == -1)
    return (my_perror(NULL));
  tcsetpgrp(STDIN_FILENO, getpgrp());
  (*tmp)->status = status;
  print_wait_status(sh, status);
  close(pipefds[1]);
  pi->input = pipefds[0];
  if ((*tmp)->separator
      && !my_strcmp((*tmp)->separator, "||") && !status)
    return (1);
  else if ((*tmp)->separator
	   && !my_strcmp((*tmp)->separator, "&&") && status)
    return (-1);
  else if ((*tmp)->prev && (*tmp)->prev->separator
  	   && !my_strcmp((*tmp)->prev->separator, "&&")
	   && (*tmp)->separator
	   && !my_strcmp((*tmp)->separator, "&&")
	   && status)
    return (-1);
  return (0);
}
