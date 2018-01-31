/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Fri May 23 17:51:00 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "my.h"
#include "mysh.h"
#include "macros.h"

static int	init_mysh(t_sh *sh, char **env)
{
  t_clm		*cl;

  if ((cl = malloc(sizeof(*cl))) == NULL)
    return (my_perror(NULL));
  sh->cl = cl;
  sh->cl->first = NULL;
  sh->cl->last = NULL;
  sh->env_list = (env) ? env_to_list(env) : NULL;
  sh->env_tab = (sh->env_list)
    ? env_list_to_tab(sh->env_list) : NULL;
  sh->path_tab = path_to_tab(sh->env_list);
  sh->var_list = NULL;
  sh->alias_list = NULL;
  sh->history.first = NULL;
  sh->history.last = NULL;
  sh->history.move = 0;
  sh->history.count = 0;
  sh->execution_pgid = -1;
  sh->exit = 0;
  if ((sh->stdin = dup(STDIN_FILENO)) == -1)
    return (-1);
  if ((sh->stdout = dup(STDOUT_FILENO)) == -1)
    return (-1);
  return (0);
}

void	siginthandling(int sig_num)
{
  (void)sig_num;
  my_putstr("\n");
  print_prompt();
}

static int	read_prompt(t_sh *sh, char *line, int exit)
{
  print_prompt();
  while ((!sh->env_list && (line = get_next_line(0)))
	 || (line = my_terminal()))
    {
      hist_put_in_list(&(sh->history), line);
      line = epur_command_line(line);
      if (line && cl_is_valid(line))
	{
	  cl_to_list(sh->cl, line);
	  exit = cl_handle(sh, sh->cl);
	  cl_free(sh->cl);
	  if (sh->exit || exit)
	    {
	      free(line);
	      free(sh->cl);
	      return ((sh->exit) ? sh->exit_value : EXIT_FAILURE);
	    }
	}
      else if (line)
	my_putstr("Syntax error.\n");
      free((line) ? line : NULL);
      print_prompt();
    }
  return (EXIT_SUCCESS);
}

t_sh		*backup_sh(t_sh *sh, int get)
{
  static t_sh	*backup = NULL;

  if (!get)
    backup = sh;
  else
    return (backup);
  return (NULL);
}

int	main(int ac, char **av, char **env)
{
  t_sh	sh;

  (void)ac;
  (void)av;
  backup_sh(&sh, 0);
  XSIGNAL(SIGTTIN, SIG_IGN);
  XSIGNAL(SIGTTOU, SIG_IGN);
  XSIGNAL(SIGINT, siginthandling);
  if (init_mysh(&sh, env) == -1)
    return (EXIT_FAILURE);
  return (read_prompt(&sh, NULL, 0));
}
