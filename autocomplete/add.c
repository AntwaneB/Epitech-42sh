/*
** add.c for add in /home/kiene_f/rendu/42sh/autocomplete
**
** Made by François KIENE
** Login   <kiene_f@epitech.net>
**
** Started on  Mon May 19 08:11:44 2014 François KIENE
** Last update Sat May 24 13:21:20 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../my.h"
#include "../mysh.h"

char		*my_autocplete_dir_exe(t_coor *coor, int *i,
				       char *str, char *open_dir)
{
  struct dirent	*rdir;
  DIR		*dir;
  int		j;
  int		k;
  int		f;
  char		*str_save;
  char		*save;

  j = *i;
  str_save = my_autocplete_stock(str, &j, &k, &f);
  if ((dir = opendir(open_dir)) == NULL)
    return (NULL);
  while (dir && (rdir = readdir(dir)) != NULL)
    {
      if (strncmp(str_save, rdir->d_name, (k)) == 0 &&
	  strncmp(".", rdir->d_name, 1) != 0 && *i > 0)
	save = my_print_autocplete(&f, save, rdir->d_name, open_dir);
    }
  my_autocplete_prompt(coor, str, f, i);
  if (f == 0 || f == 1)
    {
      str = move_cursor(save, str, k, i);
      my_reini_coor(i, str, coor);
    }
  return (str);
}

char	*my_autocplete_printstring(int *f, char *save, char *d_name)
{
  *f = *f + 1;
  if (*f == 1)
    save = my_strdup(d_name);
  my_printf("\n%s", d_name);
  return (save);
}

char		*my_autocplete_dir(t_coor *coor, int *i, char *str,
				   char *open_dir)
{
  struct dirent	*rdir;
  DIR		*dir;
  int		j;
  int		k;
  int		f;
  char		*str_save;
  char		*save;

  j = *i;
  str_save = my_autocplete_stock(str, &j, &k, &f);
  if ((dir = opendir(open_dir)) == NULL)
    return (NULL);
  while (dir && (rdir = readdir(dir)) != NULL)
    {
      if (strncmp(str_save, rdir->d_name, (k)) == 0 &&
	  strncmp(".", rdir->d_name, 1) != 0 && *i > 0)
	save = my_autocplete_printstring(&f, save, rdir->d_name);
    }
  str = my_autocplete_prompt(coor, str, f, i);
  if (f == 1)
    str = move_cursor(save, str, k, i);
  if (f == 1)
    my_reini_coor(i, str, coor);
  free(str_save);
  return (str);
}

char		*str_add(char *str_save, int k, int *f, t_sh *sh)
{
  struct dirent	*rdir;
  DIR		*dir;
  int		l;
  char		*save;

  l = 0;
  while ((dir = opendir(sh->path_tab[l])) != NULL)
    {
      while (dir && (rdir = readdir(dir)) != NULL)
	{
	  if (strncmp(str_save, rdir->d_name, (k)) == 0)
	    {
	      *f = *f + 1;
	      if (*f == 2)
		save = my_strdup(rdir->d_name);
	      else if (*f >= 2)
		my_printf("\n%s", rdir->d_name);
	    }
	}
      l = l + 1;
    }
  return (save);
}

char	*my_autocplete_exe(t_coor *coor, int *i, char *str)
{
  t_sh	*sh;
  int	j;
  int	k;
  int	f;
  char	*str_save;
  char	*save;

  sh = backup_sh(NULL, 1);
  j = *i;
  str_save = my_autocplete_stock(str, &j, &k, &f);
  save = str_add(str_save, k, &f, sh);
  if (f == 2)
    {
      my_tputs("cm", coor->save_x, coor->save_y);
      str = move_cursor(save, str, k, i);
    }
  else
    my_autocplete_prompt(coor, str, f, i);
  return (str);
}
