/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:23:04 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include "../my.h"
#include "../mysh.h"

static int	proceed_execve_no_path(t_sh *sh, t_cl *cmd)
{
  int		found;

  found = 0;
  if (cmd->cl[0][0] != '.' && cmd->cl[0][0] != '/')
    return (0);
  if (access(cmd->cl[0], X_OK) == 0)
    {
      found = 1;
      if ((execve(cmd->cl[0], cmd->cl,
		  (cmd->env) ? sh->env_tab : NULL)) == -1)
	return (my_perrorcmd("execve", cmd->cl[0]));
    }
  return (found);
}

static int	proceed_execve_path(t_sh *sh, t_cl *cmd)
{
  int		i;
  int		found;
  char		*fullpath;

  found = 0;
  i = -1;
  while (sh->path_tab && sh->path_tab[++i] && cmd->cl[0] && !found)
    {
      fullpath = my_concat3(sh->path_tab[i], "/", cmd->cl[0]);
      if (access(fullpath, X_OK) == 0)
	{
	  found = 1;
	  cmd->cl[0] = fullpath;
	  if ((execve(fullpath, cmd->cl,
		      (cmd->env) ? sh->env_tab : NULL)) == -1)
	    return (my_perror(NULL));
	}
      free(fullpath);
    }
  return (found);
}

int	my_execve(t_sh *sh, t_cl *cmd)
{
  int	found;
  char	*command;
  int	path;

  command = my_strdup(cmd->cl[0]);
  path = 1;
  if (sh->path_tab == NULL
      || cmd->cl[0][0] == '.' || cmd->cl[0][0] == '/')
    path = 0;
  if (!path)
    found = proceed_execve_no_path(sh, cmd);
  else
    found = proceed_execve_path(sh, cmd);
  if (!found)
    formated_error(command, (path)
		   ? "command not found"
		   : "No file or folder of this type");
  if (!found || found == -1)
    cmd->status = -1;
  if (!found || found == -1)
    return (-1);
  return (0);
}
