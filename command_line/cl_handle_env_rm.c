/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:50:46 2014 Thomas MORITZ
*/

#include "../my.h"
#include "../mysh.h"

static void	cl_remove_env_rm(char **cl, int i)
{
  while (cl[i] != NULL)
    {
      if (cl[i + 1] != NULL)
	cl[i] = cl[i + 2];
      else
	cl[i] = NULL;
      i++;
    }
}

void	cl_handle_env_rm(t_clm *list)
{
  int	i;
  t_cl	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->cl != NULL && tmp->cl[i] != NULL)
	{
	  if (my_strcmp(tmp->cl[i], "env") == 0 && tmp->cl[i + 1] != NULL
	      && my_strcmp(tmp->cl[i + 1], "-i") == 0)
	    {
	      cl_remove_env_rm(tmp->cl, i);
	      tmp->env = 0;
	    }
	  else
	    i++;
	}
      tmp = tmp->next;
    }
}
