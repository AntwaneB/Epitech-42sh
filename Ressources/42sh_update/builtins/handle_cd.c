/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:53:01 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "../include/mysh.h"
#include "../include/myprintf.h"
#include "../include/mystr.h"

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
  env_change_value_in_list(sh->env_list, var, cur_dir);
  if (cur_dir)
    free(cur_dir);
  return (0);
}

static int	chdir_oldpwd(t_sh *sh)
{
  char		*oldpwd;
  char		*cur_dir;

  if ((oldpwd = env_get_value_from_list(sh->env_list, "OLDPWD")) != NULL)
    {
      if ((cur_dir = my_get_current_directory()) == NULL)
	return (-1);
      if (chdir(oldpwd) == -1)
	my_printf("cd: %s: No such file or directory\n", oldpwd);
      else
	{
	  env_change_value_in_list(sh->env_list, "OLDPWD", cur_dir);
	  if (cur_dir)
	    free(cur_dir);
	}
    }
  else
    my_putstr("cd: $OLDPWD not set\n");
  return (0);
}

static int	my_exec_chdir(t_sh *sh, char *newpath)
{
  char		*cur_dir;

  if ((cur_dir = my_get_current_directory()) == NULL)
    return (-1);
  if (chdir(newpath) == -1)
    my_printf("cd: %s: No such file or directory\n", newpath);
  else
    env_change_value_in_list(sh->env_list, "OLDPWD", cur_dir);
  if (cur_dir)
    free(cur_dir);
  return (0);
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
	my_putstr("cd! $HOME not set\n");
    }
  error += change_pwdvar(sh, "PWD");
  return (error);
}
