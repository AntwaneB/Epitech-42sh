/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Fri May 16 15:52:16 2014 Antoine Buchser
*/

#include "../my.h"
#include "../mysh.h"

static int	choose_builtin(t_sh *sh, t_cl *tmp)
{
  if (my_strcmp(tmp->cl[0], "cd") == 0)
    tmp->status = handle_cd(sh, tmp);
  else if (my_strcmp(tmp->cl[0], "setenv") == 0)
    tmp->status = handle_setenv(sh, tmp);
  else if (my_strcmp(tmp->cl[0], "unsetenv") == 0)
    tmp->status = handle_unsetenv(sh, tmp);
  else if (my_strcmp(tmp->cl[0], "env") == 0)
    tmp->status = handle_env(sh, tmp);
  else if (my_strcmp(tmp->cl[0], "exit") == 0)
    return (handle_exit(sh, tmp));
  else if (my_strcmp(tmp->cl[0], "alias") == 0)
    tmp->status = handle_alias(sh, tmp);
  else if (my_strcmp(tmp->cl[0], "unalias") == 0)
    tmp->status = handle_unalias(sh, tmp);
  else if (my_strcmp(tmp->cl[0], "echo") == 0)
    tmp->status = handle_echo(sh, tmp);
  else if (my_strcmp(tmp->cl[0], "unset") == 0)
    tmp->status = handle_unset(sh, tmp);
  else if (my_strcmp(tmp->cl[0], "set") == 0)
    tmp->status = handle_set(sh, tmp);
  else if (my_strcmp(tmp->cl[0], "history") == 0)
    tmp->status = handle_history(sh, tmp);
  return (0);
}

int	handle_builtin(t_sh *sh, t_cl *tmp)
{
  if (tmp && tmp->cl && tmp->cl[0])
    return (choose_builtin(sh, tmp));
  return (0);
}
