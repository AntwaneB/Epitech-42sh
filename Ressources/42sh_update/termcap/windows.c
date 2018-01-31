/*
** windows.c for windows in /home/kiene_f/rendu/42sh/termcap
** 
** Made by François KIENE
** Login   <kiene_f@epitech.net>
** 
** Started on  Wed Apr 30 10:54:29 2014 François KIENE
** Last update Thu May  8 21:15:32 2014 Hugo Schoch
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

int	my_putc(int c)
{
  write(1, &c, 1);
  return (0);
}

int	window_row(struct termios term)
{
  char	*res;

  term.c_lflag &= ~(ICANON);
  term.c_lflag &= ~(ECHO);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSADRAIN, &term) == -1)
    return (-1);
  return (0);
}

void	my_clean()
{
  char	*res;

  res = tgetstr("cl", NULL);
  tputs(res, 1, my_putc);
  res = tgetstr("cd", NULL);
  tputs(res, 1, my_putc);
}

int			my_reset()
{
  char			*res;
  t_sh			*sh;

  sh = backup_sh(NULL, 1);
  if (tcsetattr(0, 0, &(sh->backup)) == - 1)
    return (-1);
  res = tgetstr("me", NULL);
  tputs(res, 1, my_putc);
  res = tgetstr("ve", NULL);
  tputs(res, 1, my_putc);
  res = tgetstr("ei", NULL);
  tputs(res, 1, my_putc);
  return (0);
}

int			get_value_x()
{
  struct winsize	size;

  ioctl(STDERR_FILENO, TIOCGWINSZ, &size);
  return (size.ws_col);
}
