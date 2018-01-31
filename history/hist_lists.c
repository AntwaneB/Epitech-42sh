/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May 22 16:45:03 2014 Antoine Buchser
*/

#include <stdlib.h>
#include "../my.h"
#include "../mysh.h"

int			hist_put_in_list(t_histm *list, char *line)
{
  t_hist		*elem;
  static unsigned int	pos = 0;

  if (line && line[0] != '\0')
    {
      if ((elem = malloc(sizeof(*elem))) == NULL)
	return (my_perror(NULL));
      elem->next = NULL;
      elem->prev = list->last;
      elem->line = my_strdup(line);
      elem->pos = pos;
      if (list->last)
	list->last->next = elem;
      list->last = elem;
      if (!list->first)
	list->first = elem;
      list->count++;
      pos++;
    }
  return (0);
}

char		*get_cur_line_from_hist(t_histm *list)
{
  int		i;
  t_hist	*tmp;

  if (list->count == 0)
    return (NULL);
  if (list->move > list->count)
    list->move = list->count;
  if (list->move < 1)
    {
      list->move = 0;
      return (NULL);
    }
  tmp = list->last;
  i = 1;
  while (tmp && i != list->move)
    {
      tmp = tmp->prev;
      i++;
    }
  return (tmp->line);
}

void		print_history(t_histm *list)
{
  t_hist	*tmp;

  tmp = list->first;
  while (tmp)
    {
      my_printf(" %d  %s\n", tmp->pos, tmp->line);
      tmp = tmp->next;
    }
}

void		hist_free(t_histm *list)
{
  t_hist	*tmp;
  t_hist	*rm;

  tmp = list->first;
  while (tmp)
    {
      rm = tmp;
      tmp = tmp->next;
      free(rm->line);
      free(rm);
    }
  list->first = NULL;
  list->last = NULL;
}
