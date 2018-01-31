/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:53:11 2014 Thomas MORITZ
*/

#include <string.h>
#include "../mysh.h"

char	*cl_get_writeto(t_cl *tmp, int i)
{
  if (strncmp(tmp->cl[i], ">>", 2) == 0)
    {
      if (tmp->cl[i][2] != '\0')
	return (tmp->cl[i] + 2);
      else
	return (tmp->cl[i + 1]);
    }
  else
    {
      if (tmp->cl[i][1] != '\0')
	return (tmp->cl[i] + 1);
      else
	return (tmp->cl[i + 1]);
    }
}

char	*cl_get_readfrom(t_cl *tmp, int i)
{
  if (strncmp(tmp->cl[i], "<<", 2) == 0)
    {
      if (tmp->cl[i][2] != '\0')
	return (tmp->cl[i] + 2);
      else
	return (tmp->cl[i + 1]);
    }
  else
    {
      if (tmp->cl[i][1] != '\0')
	return (tmp->cl[i] + 1);
      else
	return (tmp->cl[i + 1]);
    }
}

int	get_redir_len(char *str)
{
  if (!strncmp(str, "<<", 2) || !strncmp(str, ">>", 2))
    return (2);
  else
    return (1);
}
