/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:53:22 2014 François KIENE
*/

#include <stdlib.h>
#include <limits.h>
#include "../my.h"
#include "../mysh.h"

static char	*my_get_current_directory()
{
  char		*dest;

  if ((dest = malloc(PATH_MAX * sizeof(dest))) == NULL)
    return (NULL);
  if (getcwd(dest, PATH_MAX) == NULL)
    return (NULL);
  dest[PATH_MAX - 1] = '\0';
  return (dest);
}

static int	change_pwdvar(t_sh *sh, char *var)
{
  char		*cur_dir;

  if ((cur_dir = my_get_current_directory()) == NULL)
    return (-1);
  else
    env_change_and_update(sh, var, cur_dir);
  if (cur_dir)
    free(cur_dir);
  return (0);
}

static int	chdir_oldpwd(t_sh *sh)
{
  char		*oldpwd;
  char		*cur_dir;
  int		error;

  error = 0;
  if ((oldpwd = env_get_value_from_list(sh->env_list, "OLDPWD")) != NULL)
    {
      if ((cur_dir = my_get_current_directory()) == NULL)
	return (-1);
      if (chdir(oldpwd) == -1)
	{
	  my_perrorcmd("cd", oldpwd);
	  error = 1;
	}
      else
	env_change_and_update(sh, "OLDPWD", cur_dir);
      free((cur_dir) ? cur_dir : NULL);
    }
  else
    {
      my_putstr("cd: $OLDPWD not set\n");
      error = 1;
    }
  return (error);
}

static int	my_exec_chdir(t_sh *sh, char *newpath)
{
  char		*cur_dir;
  int		error;

  error = 0;
  if ((cur_dir = my_get_current_directory()) == NULL)
    return (-1);
  if (chdir(newpath) == -1)
    {
      my_perrorcmd("cd", newpath);
      error = 1;
    }
  else
    env_change_and_update(sh, "OLDPWD", cur_dir);
  if (cur_dir)
    free(cur_dir);
  return (error);
}

int	handle_cd(t_sh *sh, t_cl *tmp)
{
  char	*home;
  int	error;

  error = 0;
  if (tmp->cl[1] != NULL)
    {
      if (my_strcmp(tmp->cl[1], "-") != 0)
	error += my_exec_chdir(sh, tmp->cl[1]);
      else
	error += chdir_oldpwd(sh);
    }
  else
    {
      if ((home = env_get_value_from_list(sh->env_list, "HOME")) != NULL)
	error += my_exec_chdir(sh, home);
      else
	{
	  my_putstr("cd: $HOME not set\n");
	  error++;
	}
    }
  error += change_pwdvar(sh, "PWD");
  return (error);
}
