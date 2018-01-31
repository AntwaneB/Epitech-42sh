/*
** init.c for init in /home/kiene_f/rendu/42sh/termcap
**
** Made by François KIENE
** Login   <kiene_f@epitech.net>
**
** Started on  Wed May 21 13:28:13 2014 François KIENE
** Last update Sat May 24 12:48:08 2014 Antoine Buchser
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../mysh.h"

int	my_error_fscanf()
{
  char	**arg;
  t_sh	*sh;

  if (access("./mysh", X_OK) == 0)
    {
      sh = backup_sh(NULL, 1);
      if ((arg = malloc(sizeof(arg) * 2)) == NULL)
	return (0);
      if ((arg[1] = malloc(sizeof(char) * 5)) == NULL)
	return (0);
      arg[1] = strcpy(arg[1], "mysh");
      arg[2] = NULL;
      printf("\nWarning: shell termcaps (fscanf) crashed, ");
      printf("we relaunched the shell but your previous ");
      printf("modifications might be lost\n");
      my_reset();
      if (execve("./mysh", arg, sh->env_tab) == -1)
	return (my_perror(NULL));
      return (0);
    }
  else
    return (0);
}
int	my_save_ini(int save_y, int save_x, t_coor *coor)
{
  if (fprintf(stdout, "\033[6n") < 0)
    return (0);
  if ((fscanf(stdin, "\033[%d;%dR", &(save_y), &(save_x))) != 2)
    my_error_fscanf();
  if (save_y > 0 && save_y < coor->max_y)
    {
      coor->y = save_y;
      coor->y = coor->y - 1;
    }
  else
    coor->y = coor->max_y - 1;
  if (save_x > 0 && save_x < coor->max_x / 2)
    {
      coor->x = save_x;
      coor->x = coor->x - 1;
    }
  else
    coor->x = 24;
  return (0);
}

int	where_is_my_position_x(t_coor *coor, char *str)
{
  int	i;

  coor->pos_y = coor->save_y;
  coor->pos_x = coor->save_x;
  coor->x = coor->save_x;
  coor->y = coor->save_y;
  i = 0;
  while (str && str[i] != '\0')
    {
      i = i + 1;
      coor->pos_x = coor->pos_x + 1;
      coor->x = coor->x + 1;
      if (coor->pos_x >= coor->max_x)
	{
	  coor->pos_x = 0;
	  coor->x = 0;
	  coor->pos_y = coor->pos_y + 1;
	  coor->y = coor->y + 1;
	}
    }
  return (i);
}

int	my_initialization(t_coor *coor, int i)
{
  int	save_x;
  int	save_y;
  char	**arg;

  coor->max_x = get_value_x();
  coor->max_y = get_value_y();
  save_x = 0;
  save_y = 0;
  my_save_ini(save_y, save_x, coor);
  coor->save_y = coor->y;
  coor->pos_y = coor->y;
  coor->save_x = coor->x;
  coor->pos_x = coor->x;
  i = 0;
  return (i);
}
