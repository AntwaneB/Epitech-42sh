/*
** history.c for histoy in /home/kiene_f
**
** Made by François KIENE
** Login   <kiene_f@epitech.net>
**
** Started on  Wed Apr 23 12:39:48 2014 François KIENE
** Last update Sat May 24 13:19:00 2014 Antoine Buchser
*/

#include <curses.h>
#include <stdlib.h>
#include <strings.h>
#include "../my.h"
#include "../mysh.h"

char	*print_history_line(t_sh *sh, t_coor *coor, int *i)
{
  char	*line;

  my_tputs("cm", coor->save_x, coor->save_y);
  my_tputs("cd", coor->save_x, coor->save_y);
  line = get_cur_line_from_hist(&(sh->history));
  if (line)
    {
      line = my_strdup(line);
      my_putstr(line);
      *i = where_is_my_position_x(coor, line);
    }
  return (line);
}

char	*my_execution_key(char buffer[10], t_coor *coor, int *i, char *str)
{
  t_sh	*sh;

  sh = backup_sh(NULL, 1);
  if (buffer[0] == 27 && buffer[1] == '[' &&
      (buffer[2] == 65 || buffer[2] == 66))
    {
      if (buffer[2] == 65)
	sh->history.move++;
      else
	sh->history.move--;
      free(str);
      return (print_history_line(sh, coor, i));
    }
  else if (buffer[0] >= 32 && buffer[0] <= 126)
    str = my_add_character(coor, i, str, buffer);
  else if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 67)
    my_key_right(coor, i);
  else if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 68)
    my_key_left(coor, i);
  else if (buffer[0] == 127)
    str = my_key_delete(coor, i, str);
  else if (buffer[0] == 9)
    str = my_autocplete(coor, i, str, 0);
  return (str);
}

char	*my_reset_str(char *str, char buffer[10], t_sh *sh)
{
  if (str == NULL)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  str[0] = (buffer[0] == 3) ? '\0' : str[0];
  sh->history.move = 0;
  return (str);
}

char		*search_key(t_sh *sh, char *str, int i)
{
  char		buffer[10];
  char		*res;
  int		ret;
  t_coor	coor;

  i = my_initialization(&coor, i);
  while ((ret = read(0, &buffer, 10)) != -1)
    {
      if ((ret == 1 && buffer[0] == 27) || buffer[0] == 4)
	{
	  my_reset();
	  return (NULL);
	}
      else if (buffer[0] == 10 || buffer[0] == 3)
	{
	  str = my_reset_str(str, buffer, sh);
	  my_reset();
	  return (str);
	}
      else
	str = my_execution_key(buffer, &coor, &i, str);
      where_is_my_position(&coor, str);
    }
  return (NULL);
}

char			*my_terminal(void)
{
  char			*name_term;
  struct termios	term;
  t_sh			*sh;
  char			*str;
  int			i;

  sh = backup_sh(NULL, 1);
  i = 0;
  if ((str = malloc(sizeof(str) * 1)) == NULL)
    return (NULL);
  bzero(str, 1);
  if (tcgetattr(0, &(sh->backup)) == -1)
    return (NULL);
  if ((name_term =
       env_get_value_from_list(sh->env_list, "TERM")) == NULL)
    return (NULL);
  if (tgetent(NULL, name_term) == ERR)
    return (NULL);
  if (tcgetattr(0, &term) == -1)
    return (NULL);
  window_row(term);
  str = search_key(sh, str, i);
  my_putchar('\n');
  return (str);
}
