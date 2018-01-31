/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 21:31:10 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/mysh.h"
#include "../include/mystr.h"
#include "../include/myprintf.h"

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

static void	write_char_on_input(char c, int write_to)
{
  write(write_to, &c, 1);
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
  write_char_on_input(0, write_fd);
}

void		get_double_left(t_cl *tmp, int read, int write_to)
{
  static t_ldr	*list = NULL;
  static int	write_fd = -1;
  char		*line;

  if (write_fd == -1)
    write_fd = write_to;
  if (read == 1)
    {
      my_putstr("> ");
      while ((line = my_terminal()) != NULL
	     && my_strcmp(tmp->readfrom, line) != 0)
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
}
