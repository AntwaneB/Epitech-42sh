/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 23:14:35 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "include/mysh.h"
#include "include/myprintf.h"
#include "include/macros.h"
#include "include/get_next_line.h"

/*
** static void	showmylist(t_clm *cl)
** {
**  t_cl		*tmp;
**
**  tmp = cl->first;
**  while (tmp != NULL)
**   {
**     if (tmp->cl != NULL)
**	my_show_wordtab(tmp->cl);
**    if (tmp->readfrom != NULL)
**	my_printf("readfrom: %s\n", tmp->readfrom);
**    if (tmp->writeto != NULL)
**	my_printf("writeto: %s -- %d\n", tmp->writeto, tmp->writetype);
**    if (tmp->separator != NULL)
**	my_printf("===> %s\n", tmp->separator);
**    tmp = tmp->next;
**  }
** }
*/

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
  sh->pgid = getpgrp();
  sh->pid = getpid();
  sh->history = NULL;
  return (0);
}

void	siginthandling(int sig_num)
{
  (void)sig_num;
  my_putstr("\n");
  my_putstr(PROMPT);
}

static int	read_prompt(t_sh *sh, char *line, int exit)
{
  my_printf(PROMPT);
  while ((!sh->env_list && (line = get_next_line(0)))
	 || (line = my_terminal()))
    {
      //      save_history(sh, line);
      line = epur_command_line(line);
      if (cl_is_valid(line))
	{
	  cl_to_list(sh->cl, line);
	  exit = cl_handle(sh, sh->cl);
	  cl_free(sh->cl);
	  if (exit)
	    {
	      free(line);
	      free(sh->cl);
	      return ((exit == -1) ? EXIT_SUCCESS : exit);
	    }
	}
      else
	my_putstr("Syntax error.\n");
      free(line);
      my_printf(PROMPT);
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
