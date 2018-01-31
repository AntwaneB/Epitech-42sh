/*
** initialisation.c for initialisation.c in /home/kiene_f/rendu/42sh/autocomplete
**
** Made by François KIENE
** Login   <kiene_f@epitech.net>
**
** Started on  Mon May 19 08:14:17 2014 François KIENE
** Last update Sat May 24 13:07:20 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

char	*my_name_add(char *name, char *open_dir, char *dir_name)
{
  name = strcpy(name, open_dir);
  name = strcat(name, dir_name);
  return (name);
}

int	my_ini_autocplete(int *j, int *f, char *str)
{
  while (*j >= 0 && str[*j] != ' ')
    *j = *j - 1;
  *f = *j;
  *j = *j + 1;
  return (0);
}

char	*exec_dir(t_coor *coor, int *i, char *str, int j)
{
  char	*dir;
  int	l;
  int	k;
  int	f;

  l = j;
  if ((dir = malloc(sizeof(dir) * (*i - j + 1))) == NULL)
    return (NULL);
  k = my_ini_autocplete(&j, &f, str);
  while (j != l + 1)
    {
      dir[k] = str[j];
      k = k + 1;
      j = j + 1;
    }
  dir[k] = '\0';
  str = (f > 0) ? my_autocplete_dir(coor, i, str, dir)
    : my_autocplete_dir_exe(coor, i, str, dir);
  free(dir);
  return (str);
}

char	*my_exec_autocplete(t_coor *coor, int *i, char *str, int j)
{
  my_tputs("cm", coor->save_x, coor->save_y);
  while (j > 0 && str[j] != '/' && str[j] != ' ')
    j = j - 1;
  if (str[j] == '/')
    str = exec_dir(coor, i, str, j);
  else
    str = my_autocplete_dir(coor, i, str, ".");
  return (str);
}

char	*my_autocplete(t_coor *coor, int *i, char *str, int k)
{
  int	j;

  j = *i;
  while (j > 0 && str[j] != ' ' && str[j] != '|' && str[j] != ';'
	 && str[j] != '&')
    j = j - 1;
  while (j > 0 && str[j] == ' ')
    {
      j = j - 1;
      k = 1;
    }
  if ((j == 0 && k == 0 && ((str[j] >= 'a' && str[j] <= 'z') ||
			    (str[j] >= 'A' && str[j] <= 'Z')))
      || str[j] == '|' || str[j] == ';' || str[j] == '&')
    str = my_autocplete_exe(coor, i, str);
  else if ((j == 0 && k == 0) ||
	   (k == 1 && (((str[j] >= 'a' && str[j] <= 'z') ||
			(str[j] >= 'A' && str[j] <= 'Z')))))
    {
      j = *i;
      str = my_exec_autocplete(coor, i, str, j);
    }
  if (str != NULL)
    *i = where_is_my_position_x(coor, str);
  return (str);
}
