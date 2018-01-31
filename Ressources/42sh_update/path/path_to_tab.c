/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 22:06:12 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

static int	fill_path_tab(char **path, char *path_tmp)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  while (i < get_nb_of_path(path_tmp))
    {
      if ((path[i] = malloc((my_strlen(path_tmp) + 1)
			    * sizeof(**path))) == NULL)
	return (my_perror(NULL));
      k = 0;
      while (path_tmp[j] != ':' && path_tmp[j] != '\0')
	{
	  path[i][k] = path_tmp[j];
	  j++;
	  k++;
	}
      path[i][k] = '\0';
      j++;
      i++;
    }
  path[i] = NULL;
  return (0);
}

char	**path_to_tab(t_env *env_list)
{
  char	**path_tab;
  char	*path_line;

  path_line = env_get_value_from_list(env_list, "PATH");
  if (path_line != NULL)
    {
      if ((path_tab = malloc((get_nb_of_path(path_line) + 1)
			     * sizeof(*path_tab))) == NULL)
	{
	  my_perror(NULL);
	  return (NULL);
	}
      if (fill_path_tab(path_tab, path_line) == -1)
	return (NULL);
      return (path_tab);
    }
  else
    return (NULL);
}
