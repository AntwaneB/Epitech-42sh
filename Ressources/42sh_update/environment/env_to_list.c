/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 18:25:23 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

t_env	*env_to_list(char **env)
{
  t_env	*env_list;
  int	i;
  int	j;
  char	*name;
  char	*value;

  env_list = NULL;
  i = 0;
  while (env != NULL && env[i] != NULL)
    {
      j = 0;
      while (env[i][j] != '=')
	j++;
      name = my_strndup(env[i], j);
      value = my_strdup(env[i] + j + 1);
      env_put_in_list(&env_list, name, value);
      i++;
    }
  return (env_list);
}
