/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 20:40:15 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../include/mysh.h"

int	get_nb_of_path(char *pathline)
{
  int	i;
  int	path_nb;

  path_nb = 0;
  i = 0;
  while (pathline[i] != '\0')
    {
      if (pathline[i] == ':' || pathline[i + 1] == '\0')
	path_nb++;
      i++;
    }
  return (path_nb);
}
