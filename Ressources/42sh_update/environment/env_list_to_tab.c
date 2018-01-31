/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 18:26:15 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

void	env_fill_tab_line(char **env_tab, int i, char *name, char *value)
{
  env_tab[i][0] = '\0';
  my_strcat(env_tab[i], name);
  my_strcat(env_tab[i], "=");
  if (value != NULL)
    my_strcat(env_tab[i], value);
}

char	**env_list_to_tab(t_env *env_list)
{
  char	**env_tab;
  t_env	*tmp;
  int	env_size;
  int	i;
  int	malloc_len;

  tmp = env_list;
  env_size = env_list_size(env_list);
  if ((env_tab = malloc((env_size + 1) * sizeof(*env_tab))) == NULL)
    return ((my_perror(NULL)) ? NULL : NULL);
  i = 0;
  while (i < env_size)
    {
      malloc_len = my_strlen(tmp->name) + 2;
      if (tmp->value != NULL)
	malloc_len += my_strlen(tmp->value);
      if ((env_tab[i] = malloc(malloc_len * sizeof(**env_tab))) == NULL)
	return ((my_perror(NULL)) ? NULL : NULL);
      env_fill_tab_line(env_tab, i, tmp->name, tmp->value);
      tmp = tmp->next;
      i++;
    }
  env_tab[i] = NULL;
  return (env_tab);
}
