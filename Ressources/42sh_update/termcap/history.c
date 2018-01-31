/*
** history.c for 42sh in /home/schoch_h/Projets/42sh_update/termcap
** 
** Made by Hugo Schoch
** Login   <schoch_h@epitech.net>
** 
** Started on  Thu May  8 21:10:24 2014 Hugo Schoch
** Last update Thu May  8 21:11:36 2014 Hugo Schoch
*/

#include <curses.h>
#include <term.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <linux/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <strings.h>
#include "../include/mysh.h"
#include "../include/myprintf.h"

char	*my_execution_key(char buffer[10], t_coor *coor, int *i, char *str)
{
  if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 65)
    printf("historique up\n");
  else if (buffer[0] >= 32 && buffer[0] <= 126)
    str = my_add_character(coor, i, str, buffer);
  else if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 67)
    my_key_right(coor, i);
  else if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 68)
    my_key_left(coor, i);
  else if (buffer[0] == 127)
    str = my_key_delete(coor, i, str);
  return (str);
}

char		*search_key(char *str, int i)
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
	  if (buffer[0] == 3)
	    str[0] = '\0';
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
  if ((str = malloc(sizeof(str) * 1000)) == NULL)
    return (NULL);
  bzero(str, 1000);
  if (tcgetattr(0, &(sh->backup)) == -1)
    return (NULL);
  if ((name_term = getenv("TERM")) == NULL)
    return (NULL);
  if (tgetent(NULL, name_term) == ERR)
    return (NULL);
  if (tcgetattr(0, &term) == -1)
    return (NULL);
  window_row(term);
  str = search_key(str, i);
  my_putchar('\n');
  return (str);
}
