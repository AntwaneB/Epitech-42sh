/*
** my_key.c for my_key in /home/kiene_f/rendu/42sh/termcap
** 
** Made by François KIENE
** Login   <kiene_f@epitech.net>
** 
** Started on  Wed Apr 30 10:58:08 2014 François KIENE
** Last update Sat May 24 12:58:02 2014 Antoine Buchser
*/

#include "../my.h"
#include "../mysh.h"

void	my_key_right(t_coor *coor, int *i)
{
  coor->x = coor->x + 1;
  *i = *i + 1;
  if (coor->pos_y == coor->y && (coor->pos_x + 1) <= coor->x)
    {
      coor->x = coor->x - 1;
      *i = *i - 1;
    }
  my_check_size_term(coor);
  my_tputs("cm", coor->x, coor->y);
}

void	my_key_left(t_coor *coor, int *i)
{
  coor->x = coor->x - 1;
  *i = *i - 1;
  if (coor->save_y == coor->y && (coor->save_x - 1) >= coor->x)
    {
      coor->x = coor->x + 1;
      *i = *i + 1;
    }
  my_check_size_term(coor);
  my_tputs("cm", coor->x, coor->y);
}

char	*remove_caracter(t_coor *coor, int *i, char *str)
{
  int	j;

  if (coor->save_y == coor->y && (coor->save_x - 1) == coor->x)
    {
      *i = *i + 1;
      coor->x = coor->x + 1;
      my_check_size_term(coor);
    }
  else
    {
      my_tputs("cm", coor->x, coor->y);
      my_tputs("dc", coor->x, coor->y);
      j = *i;
      while (str[j] != '\0')
	{
	  str[j] = str[j + 1];
	  j = j + 1;
	}
    }
  return (str);
}

char	*my_key_delete(t_coor *coor, int *i, char *str)
{
  int	j;

  coor->x = coor->x - 1;
  *i = *i - 1;
  my_check_size_term(coor);
  str = remove_caracter(coor, i, str);
  if (*i < 0)
    *i = 0;
  j = *i;
  my_tputs("cd", coor->x, coor->y);
  while (str[j] != '\0')
    {
      my_putchar(str[j]);
      j = j + 1;
    }
  my_tputs("cm", coor->x, coor->y);
  return (str);
}
