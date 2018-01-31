/*
** autocomplete.c for autocomplete in /home/kiene_f/rendu/42sh/autocomplete
**
** Made by François KIENE
** Login   <kiene_f@epitech.net>
**
** Started on  Mon May 19 08:06:28 2014 François KIENE
** Last update Sat May 24 13:24:05 2014 Antoine Buchser
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "../my.h"
#include "../mysh.h"

char	*my_autocplete_prompt(t_coor *coor, char *str, int f, int *i)
{
  my_putchar('\n');
  print_prompt();
  my_initialization(coor, 0);
  if (f > 1)
    {
      my_putstr(str);
      where_is_my_position_x(coor, str);
    }
  my_tputs("cm", coor->x, coor->y);
  return (str);
}

char		*move_cursor(char *save, char *str, int k, int *i)
{
  int		j;

  j = 0;
  while (save[k] != '\0')
    {
      str[*i] = '\0';
      j = (str) ? my_strlen(str) : 0;
      if ((str = realloc(str, sizeof(str) * (j + 1))) == NULL)
	return (NULL);
      str[j + 1] = '\0';
      while (j >= *i)
	{
	  str[j] = str[j - 1];
	  j = j - 1;
	}
      str[*i] = save[k];
      *i = *i + 1;
      k = k + 1;
    }
  str[*i] = '\0';
  j = -1;
  while (str[++j] != '\0')
    my_putchar(str[j]);
  return (str);
}

char		*my_print_autocplete(int *f, char *save,
				     char *dir_name, char *open_dir)
{
  struct stat	filestat;
  char		*name;

  if ((name = malloc(sizeof(name) *
		     (strlen(open_dir) + strlen(dir_name) + 1))) == NULL)
    return (NULL);
  name = my_name_add(name, open_dir, dir_name);
  if (stat(name, &filestat) >= 0)
    {
      if (S_ISDIR(filestat.st_mode) != 0 ||
	  ((filestat.st_mode & S_IXUSR) != 0 ||
	   (filestat.st_mode & S_IXGRP) != 0 ||
	   (filestat.st_mode & S_IXOTH) != 0))
	{
	  *f = *f + 1;
	  if (*f == 1)
	    save = my_strdup(dir_name);
	  if (S_ISDIR(filestat.st_mode) != 0)
	    my_printf("\n%s/", dir_name);
	  else
	    my_printf("\n%s", dir_name);
	}
    }
  free(name);
  return (save);
}

char	*my_autocplete_stock(char *str, int *j, int *k, int *f)
{
  char	*str_save;

  while (*j >= 0 && str[*j] != ' ' && str[*j] != '/')
    *j = *j - 1;
  *j = *j + 1;
  *k = 0;
  if ((str_save = malloc(sizeof(str_save) * 10)) == NULL)
    return (my_perror(NULL) ? NULL : NULL);
  while (str[*j] != '\0' && str[*j] != ' ')
    {
      str_save[*k] = str[*j];
      *j = *j + 1;
      *k = *k + 1;
    }
  str_save[*k] = '\0';
  *f = 0;
  return (str_save);
}

void	my_reini_coor(int *i, char *str, t_coor *coor)
{
  where_is_my_position(coor, str);
}
