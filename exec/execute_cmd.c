/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 14:37:21 2014 Antoine Buchser
*/

#include <sys/wait.h>
#include <fcntl.h>
#include "../mysh.h"
#include "../macros.h"

int	proceed_exec(t_sh *sh, t_cl *cmd,
		     int read_fd, int write_fd)
{
  int	ret;
  int	pipeldr[2];

  if (init_double_left(sh, cmd, &read_fd) != 0)
    return (-1);
  if (dup2(read_fd, STDIN_FILENO) == -1)
    return (my_perrorcmd("dup2", "stdin"));
  if (cmd->readfrom && cmd->readtype == 2)
    get_double_left(sh, cmd, 0, 0);
  if (cmd->readfrom && cmd->readtype == 2)
    close_pipefds(read_fd, STDIN_FILENO);
  if (dup2(write_fd, STDOUT_FILENO) == -1)
    return (my_perrorcmd("dup2", "stdout"));
  ret = (!is_builtin(sh, cmd)) ? my_execve(sh, cmd)
    : handle_builtin(sh, cmd);
  if (is_builtin(sh, cmd))
    {
      if (dup2(sh->stdin, STDIN_FILENO) == -1)
	return (my_perrorcmd("dup2", NULL));
      if (dup2(sh->stdout, STDOUT_FILENO) == -1)
	return (my_perrorcmd("dup2", NULL));
    }
  return (ret);
}

int	get_fds(t_sh *sh, t_cl *cmd, int *pipefds, int *write_fd)
{
  int	flags;
  int	pipeldr[2];

  if (cmd->writeto)
    {
      close_pipefds(pipefds[1], STDOUT_FILENO);
      if ((*write_fd = open(cmd->writeto, (cmd->writetype == 2)
			    ? O_WRONLY | O_APPEND | O_CREAT
			    : O_WRONLY | O_TRUNC | O_CREAT,
			    S_IRUSR | S_IWUSR | S_IROTH)) == -1)
	return (my_perrorcmd("open", cmd->writeto));
    }
  if (cmd->readfrom)
    {
      if (cmd->readtype == 1 && cmd->readfrom)
	if ((pipefds[0] = open(cmd->readfrom, O_RDONLY,
			       S_IRUSR | S_IRGRP)) == -1)
	  return (my_perrorcmd("open", cmd->writeto));
    }
  return (0);
}

int	init_pipeline(t_sh *sh, t_cl *tmp)
{
  int	ret;

  if (tmp)
    {
      if ((ret = execute_type(sh, &tmp)) != 0)
	return (ret);
      if (tmp)
	if ((ret = init_pipeline(sh, tmp)) != 0)
	  return (ret);
    }
  return (0);
}

int	execute_cmd(t_sh *sh)
{
  t_cl	*tmp;
  int	pid;
  int	status;

  tmp = sh->cl->first;
  sh->execution_pgid = -1;
  if ((status = init_pipeline(sh, tmp)) != 0)
    return (status);
  XSIGNAL(SIGTTOU, SIG_IGN);
  if (dup2(sh->stdin, STDIN_FILENO) == -1)
    return (my_perrorcmd("dup2", NULL));
  if (dup2(sh->stdout, STDOUT_FILENO) == -1)
    return (my_perrorcmd("dup2", NULL));
  if (tcsetpgrp(STDIN_FILENO, getpgrp()) == -1)
    return (my_perrorcmd("tcsetpgrp", NULL));
  return (0);
}
