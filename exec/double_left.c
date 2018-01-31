/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:08:35 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <string.h>
#include "../my.h"
#include "../mysh.h"

static int	ldr_put_in_list(t_ldr **list, char *line)
{
  t_ldr		*elem;
  t_ldr		*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (my_perror(NULL));
  elem->line = line;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
  return (0);
}

static void	write_on_input(char *str, int write_to)
{
  write(write_to, str, my_strlen(str));
}

static void	write_all_ldr(t_ldr *list, int write_fd)
{
  t_ldr		*rm;
  t_ldr		*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      rm = tmp;
      write_on_input(tmp->line, write_fd);
      write_on_input("\n", write_fd);
      tmp = tmp->next;
      free(rm);
    }
}

int		init_double_left(t_sh *sh, t_cl *cmd, int *read_fd)
{
  int		pipeldr[2];

  if (cmd->readfrom && cmd->readtype == 2)
    {
      if (pipe(pipeldr) == -1)
	return (my_perrorcmd("pipe", NULL));
      *read_fd = pipeldr[0];
      get_double_left(sh, cmd, 1, pipeldr[1]);
    }
  return (0);
}

int		get_double_left(t_sh *sh, t_cl *tmp,
				int read, int write_to)
{
  static t_ldr	*list = NULL;
  static int	write_fd = -1;
  char		*line;
  int		fd;

  write_fd = (write_fd == -1) ? write_to : write_fd;
  fd = write_fd;
  if (read == 1)
    {
      my_putstr("> ");
      while ((line = get_next_line(0)) != NULL
	     && strcmp(tmp->readfrom, line) != 0)
	{
	  ldr_put_in_list(&list, line);
	  my_putstr("> ");
	}
    }
  else
    {
      write_all_ldr(list, write_fd);
      close(write_fd);
      list = NULL;
      write_fd = -1;
    }
  return (fd);
}
