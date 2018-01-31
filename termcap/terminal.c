/*
** terminal.c for terminal in /home/kiene_f/rendu/42sh/termcap
** 
** Made by François KIENE
** Login   <kiene_f@epitech.net>
** 
** Started on  Wed Apr 30 10:56:40 2014 François KIENE
** Last update Sat May 24 12:58:09 2014 Antoine Buchser
*/

#include <sys/ioctl.h>
#include <stdlib.h>
#include "../my.h"
#include "../mysh.h"

int			get_value_y()
{
  struct winsize	size;

  ioctl(STDERR_FILENO, TIOCGWINSZ, &size);
  return (size.ws_row);
}

void	my_check_size_term(t_coor *coor)
{
  if (coor->x >= coor->max_x && coor->y <= coor->max_y)
    {
      coor->x = 0;
      my_putchar('\n');
      coor->y = coor->y + 1;
    }
  else if (coor->x >= coor->max_x && coor->y > coor->max_y)
    coor->y = coor->max_y - 1;
  else if (coor->x < 0)
    {
      coor->x = coor->max_x;
      coor->y = coor->y - 1;
    }
}

int	where_is_my_position(t_coor *coor, char *str)
{
  int	i;

  coor->pos_y = coor->save_y;
  coor->pos_x = coor->save_x;
  i = 0;
  while (str && str[i] != '\0')
    {
      i = i + 1;
      coor->pos_x = coor->pos_x + 1;
      if (coor->pos_x >= coor->max_x)
	{
	  coor->pos_x = 0;
	  coor->pos_y = coor->pos_y + 1;
	}
    }
  return (0);
}

void	my_tputs(char *ft, int x, int y)
{
  char	*res;

  res = tgetstr(ft, NULL);
  tputs(tgoto(res, x, y), 1, my_putc);
}

char	*my_add_character(t_coor *coor, int *i,
			  char *str, char buffer[10])
{
  char	*res;
  int	j;

  j = (str) ? my_strlen(str) : 0;
  res = tgetstr("ic", NULL);
  tputs(res, 1, my_putc);
  my_putchar(buffer[0]);
  if ((str = realloc(str, sizeof(str) * (j + 1))) == NULL)
    return (NULL);
  str[j + 1] = '\0';
  while (j > *i)
    {
      str[j] = str[j - 1];
      j = j - 1;
    }
  str[*i] = buffer[0];
  *i = *i + 1;
  coor->x = coor->x + 1;
  j = *i - 1;
  while (str[++j] != '\0')
    my_putchar(str[j]);
  my_check_size_term(coor);
  my_tputs("cm", coor->x, coor->y);
  return (str);
}
