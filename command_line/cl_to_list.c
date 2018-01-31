/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:54:24 2014 Thomas MORITZ
*/

#include <string.h>
#include "../my.h"
#include "../mysh.h"

static void	cl_remove_redirection(char **cl, int i)
{
  while (cl[i])
    {
      if (is_redirection(cl[i]))
	{
	  if (my_strlen(cl[i]) == 1
	      || (my_strlen(cl[i]) == 2 && cl[i][0] == cl[i][1]))
	    {
	      wtab_remove_one_line(cl, i);
	      wtab_remove_one_line(cl, i);
	    }
	  else
	    wtab_remove_one_line(cl, i);
	}
      i++;
    }
}

static void	fill_redirection_type(t_cl *tmp, char *redirection)
{
  if (strncmp(redirection, ">>", 2) == 0)
    tmp->writetype = 2;
  else if (redirection[0] == '>' && redirection[1] != '>')
    tmp->writetype = 1;
  else if (strncmp(redirection, "<<", 2) == 0)
    tmp->readtype = 2;
  else if (redirection[0] == '<' && redirection[1] != '<')
    tmp->readtype = 1;
}

static void	cl_handle_redir(t_clm *list)
{
  int		i;
  t_cl		*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->cl != NULL && tmp->cl[i] != NULL)
	{
	  if (is_redirection(tmp->cl[i]) == 2)
	    tmp->writeto = cl_get_writeto(tmp, i);
	  else if (is_redirection(tmp->cl[i]) == 1)
	    tmp->readfrom = cl_get_readfrom(tmp, i);
	  if (is_redirection(tmp->cl[i]))
	    fill_redirection_type(tmp, tmp->cl[i]);
	  if (is_redirection(tmp->cl[i]))
	    cl_remove_redirection(tmp->cl, i);
	  else
	    i++;
	}
      tmp = tmp->next;
    }
}

int	cl_to_list(t_clm *list, char *cl)
{
  int	i;
  int	j;
  char	*sep;

  i = 0;
  j = 0;
  while (cl && cl[i])
    {
      if (is_separator(cl + i) != 0 || cl[i + 1] == '\0')
	{
	  sep = (cl[i + 1] != '\0') ? get_separator(cl + i) : NULL;
	  if (cl[i + 1] != '\0')
	    cl[i] = '\0';
	  if (sep != NULL && sep[1] != '\0')
	    cl[i + 1] = '\0';
	  if (cl_put_in_list(list, my_explode_quotes(cl + j), sep) == -1)
	    return (-1);
	  i = (sep != NULL && sep[1] != '\0') ? i + 1 : i;
	  j = i + 1;
	}
      i++;
    }
  cl_handle_redir(list);
  cl_handle_env_rm(list);
  return (0);
}
