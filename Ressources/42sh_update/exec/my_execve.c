/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:20:43 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/mysh.h"
#include "../include/macros.h"

static int	launch_program_no_path(t_cl *tmp, t_sh *sh)
{
  int		found;

  found = 0;
  if (access(tmp->cl[0], X_OK) == 0)
    {
      found = 1;
      if ((execve(tmp->cl[0], tmp->cl,
		  (tmp->env == 1) ? sh->env_tab : NULL)) == -1)
	my_error("execve() failed.");
    }
  if (!found)
    formated_error(tmp->cl[0],
		   "No file or folder or this type");
  if (!found)
    exit(-1);
  return (found);
}

static int	launch_program(t_cl *tmp, t_sh *sh)
{
  int		i;
  int		found;
  char		*fullpath;

  found = 0;
  i = -1;
  while (sh->path_tab != NULL && sh->path_tab[++i] != NULL
	 && tmp->cl[0] != NULL && found == 0)
    {
      fullpath = my_concat3(sh->path_tab[i], "/", tmp->cl[0]);
      if (access(fullpath, X_OK) == 0)
        {
          found = 1;
	  tmp->cl[0] = fullpath;
	  if ((execve(fullpath, tmp->cl,
		      (tmp->env == 1) ? sh->env_tab : NULL)) == -1)
	    my_error("execve() failed.");
        }
      free(fullpath);
    }
  if (!found)
    formated_error(tmp->cl[0], "command not found");
  if (!found)
    exit(-1);
  return (found);
}

static char	*proceed_child(t_sh *sh, int *pipefds,
			       t_pid *pi, t_cl *tmp)
{
  int		newfds[2];

  get_input_fds(pipefds, newfds, tmp, pi);
  if (dup2(newfds[0], newfds[1]) == -1)
    my_error("dup2() failed.");
  if (tmp->readfrom != NULL && tmp->readtype == 2)
    get_double_left(tmp, 0, 0);
  if (tmp->readfrom != NULL && tmp->readtype == 2)
    close(newfds[0]);
  get_output_fds(pipefds, newfds, tmp, pi);
  if (dup2(newfds[0], newfds[1]) == -1)
    my_error("dup2() failed.");
  close(pipefds[0]);
  if (sh->path_tab == NULL
      || tmp->cl[0][0] == '.' || tmp->cl[0][0] == '/')
    {
      if (launch_program_no_path(tmp, sh) == 0)
	return (tmp->cl[0]);
    }
  else
    {
      if (launch_program(tmp, sh) == 0)
	return (tmp->cl[0]);
    }
  return (NULL);
}

static int	proceed_exec(t_sh *sh, int *pipefds,
			     t_cl *tmp, t_pid *pi)
{
  static int	proceed_next = 0;

  if (proceed_next == 0)
    {
      if (pipe(pipefds) == -1)
     	return (my_perror(NULL));
      if ((pi->pid = fork()) == -1)
	return (my_perror(NULL));
      else if (pi->pid == 0)
	{
	  if (setpgid(0, 0) == -1)
	    my_error("setpgid() failed.\n");
	  XSIGNAL(SIGTTOU, SIG_IGN);
	  if (tcsetpgrp(STDIN_FILENO, getpgrp()) == -1)
	    my_error("tcsetpgrp() failed.\n");
	  XSIGNAL(SIGINT, SIG_DFL);
	  proceed_child(sh, pipefds, pi, tmp);
	}
      else
	proceed_next = proceed_father(sh, pipefds, &tmp, pi);
    }
  else
    proceed_next = 0;
  return (0);
}

void	my_execve(t_sh *sh)
{
  int	pipefds[2];
  t_cl	*tmp;
  t_pid	pi;

  pi.input = 0;
  tmp = sh->cl->first;
  while (tmp)
    {
      if (proceed_exec(sh, pipefds, tmp, &pi) != 0)
	exit(0);
      tmp = (tmp) ? tmp->next : NULL;
    }
}
