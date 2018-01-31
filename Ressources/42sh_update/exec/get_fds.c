/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:27:53 2014 Hugo Schoch
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

void	get_input_fds(int *pipefds, int *newfds, t_cl *tmp, t_pid *pi)
{
  int	pipeldr[2];

  if (tmp->readfrom != NULL)
    {
      if (tmp->readtype == 2)
	{
	  if (pipe(pipeldr) == -1)
	    my_error("pipe() failed.\n");
	  newfds[0] = pipeldr[0];
	  get_double_left(tmp, 1, pipeldr[1]);
	}
      else
	{
	  if ((newfds[0] = open(tmp->readfrom, O_RDONLY,
				S_IRUSR | S_IRGRP)) == -1)
	    my_error("open() failed.\n");
	}
    }
  else if (tmp->prev != NULL
	   && my_strcmp(tmp->prev->separator, "|") == 0)
    newfds[0] = pi->input;
  else
    newfds[0] = 0;
  newfds[1] = 0;
}

void	get_output_fds(int *pipefds, int *newfds, t_cl *tmp, t_pid *pi)
{
  int	flags;

  if (tmp->writeto != NULL)
    {
      if (tmp->writetype == 2)
	flags = O_WRONLY | O_APPEND | O_CREAT;
      else
	flags = O_WRONLY | O_TRUNC | O_CREAT;
      if ((newfds[0] = open(tmp->writeto, flags,
			    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	my_error("open() failed.\n");
    }
  else if (tmp->separator != NULL && my_strcmp(tmp->separator, "|") == 0)
    newfds[0] = pipefds[1];
  else
    newfds[0] = 1;
  newfds[1] = 1;
}
