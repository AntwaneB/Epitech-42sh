/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:36:50 2014 Antoine Buchser
*/

#include <sys/wait.h>
#include "../mysh.h"
#include "../macros.h"

static int	set_to_foreground(t_sh *sh, t_cl *cmd)
{
  if (!is_builtin(sh, cmd))
    {
      if (sh->execution_pgid == -1)
	{
	  if (setpgid(0, 0) == -1)
	    return (my_perrorcmd("setpgid", NULL));
	  XSIGNAL(SIGTTOU, SIG_IGN);
	  if (tcsetpgrp(STDIN_FILENO, getpgrp()) == -1)
	    return (my_perrorcmd("tcsetpgrp", NULL));
	  XSIGNAL(SIGINT, SIG_DFL);
	  sh->execution_pgid = getpgrp();
	}
      else
	if (setpgid(0, sh->execution_pgid) == -1)
	  return (my_perrorcmd("setpgid", NULL));
    }
  return (0);
}

static void	proceed_father(t_sh *sh, t_cl *cmd,
			       int *pipefds, int write_fd)
{
  cmd->write_fd = write_fd;
  close_pipefds(pipefds[0], 0);
  if (cmd->prev && cmd->prev->separator && is_pipe(cmd->prev->separator))
    multipipe_line(sh, cmd->prev, pipefds[1]);
}

static int	proceed_son(t_sh *sh, t_cl *cmd, int *pipefds, int write_fd)
{
  int		ret;

  if ((ret = set_to_foreground(sh, cmd)) != 0)
    return (ret);
  if (!is_builtin(sh, cmd))
    close_pipefds(pipefds[1], 1);
  if ((ret = proceed_exec(sh, cmd, pipefds[0], write_fd)) != 0)
    return (ret);
  return (0);
}

int	multipipe_line(t_sh *sh, t_cl *cmd, int write_fd)
{
  int	pid;
  int	ret;
  int	pipefds[2];

  ali_handle(sh, cmd);
  var_handle(sh, cmd);
  reset_pipefds(pipefds);
  if (cmd->prev && cmd->prev->separator && is_pipe(cmd->prev->separator))
    if (pipe(pipefds) == -1)
      return (my_perrorcmd("pipe", NULL));
  if ((cmd->status = get_fds(sh, cmd, pipefds, &write_fd)) != 0)
    return (0);
  pid = 0;
  if (!is_builtin(sh, cmd) && ((pid = fork()) == -1))
    return (my_perrorcmd("fork", NULL));
  if (pid == 0)
    if ((ret = proceed_son(sh, cmd, pipefds, write_fd)) != 0)
      return (ret);
  if (!is_builtin(sh, cmd) && sh->execution_pgid == -1)
    sh->execution_pgid = pid;
  proceed_father(sh, cmd, pipefds, write_fd);
  cmd->pid = pid;
  return (0);
}
