/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 18:00:47 2014 Hugo Schoch
*/

#include "../include/mysh.h"
#include "../include/mystr.h"

char	*cl_get_writeto(t_cl *tmp, int i)
{
  if (my_strncmp(tmp->cl[i], ">>", 2) == 0)
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
  if (my_strncmp(tmp->cl[i], "<<", 2) == 0)
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
  if (!my_strncmp(str, "<<", 2) || !my_strncmp(str, ">>", 2))
    return (2);
  else
    return (1);
}
