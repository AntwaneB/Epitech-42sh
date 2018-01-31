/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 14:37:44 2014 Antoine Buchser
*/

#include <sys/wait.h>
#include "../mysh.h"
#include "../macros.h"

static int	is_execute_non_pipe(t_sh *sh, t_cl *tmp)
{
  if (tmp
      && (!(tmp->prev)
	  || (tmp->prev && tmp->prev->separator
	      && is_and(tmp->prev->separator)
	      && tmp->prev->status == 0)
	  || (tmp->prev && tmp->prev->separator
	      && is_or(tmp->prev->separator)
	      && tmp->prev->status != 0)
	  || (tmp->prev && tmp->prev->separator
	      && is_semicol(tmp->prev->separator))))
    return (1);
  else
    return (0);
}

static int	proceed_execute_pipe(t_sh *sh, t_cl **tmp)
{
  t_cl		*back;
  int		ret;

  back = *tmp;
  while (*tmp && (*tmp)->separator && is_pipe((*tmp)->separator))
    *tmp = (*tmp)->next;
  if ((ret = multipipe_line(sh, *tmp, 1)) != 0)
    return (ret);
  while (back && (is_pipe(back->separator)
		  || is_pipe(back->prev->separator)))
    {
      if (!is_builtin(sh, back) && back->status != -1)
	XWPID(back->pid, &(back->status));
      close_pipefds(back->write_fd, 1);
      if (back->status != 0 && !is_builtin(sh, back))
	print_wait_status(sh, back->status);
      back = back->next;
    }
  return (0);
}

int	execute_type(t_sh *sh, t_cl **tmp)
{
  int	ret;

  if (*tmp && (*tmp)->separator && is_pipe((*tmp)->separator))
    {
      sh->execution_pgid = -1;
      if ((ret = proceed_execute_pipe(sh, tmp)) != 0)
	return (ret);
    }
  else if (is_execute_non_pipe(sh, *tmp))
    {
      sh->execution_pgid = -1;
      if ((ret = multipipe_line(sh, *tmp, 1)) != 0)
	return (ret);
      if (!is_builtin(sh, *tmp) && (*tmp)->status != -1)
	XWPID((*tmp)->pid, &((*tmp)->status));
      if ((*tmp)->status != 0 && !is_builtin(sh, *tmp))
	print_wait_status(sh, (*tmp)->status);
      (*tmp) = (*tmp)->next;
    }
  else
    (*tmp) = (*tmp)->next;
  return (0);
}
