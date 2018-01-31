/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:51:33 2014 Thomas MORITZ
*/

#include "../mysh.h"

static int	check_following_chars(char *str)
{
  int		i;

  if (is_separator(str) == 2 || is_redirection_len(str) == 2)
    i = 2;
  else
    i = 1;
  while (str[i] && str[i] != '|' && str[i] != '&'
	 && str[i] != ';')
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
      i++;
    }
  return (0);
}

static int	count_quotes(char *str)
{
  int		i;
  int		count;

  count = 0;
  i = -1;
  while (str[++i])
    count = (str[i] == '"') ? count + 1 : count;
  return (count);
}

int	cl_is_valid(char *cl)
{
  int	i;
  int	check;

  if (count_quotes(cl) % 2 != 0)
    return (0);
  i = 0;
  check = 1;
  while (cl[i] && check == 1)
    {
      if (cl[i] >= 0)
	{
	  if (i > 0 && (is_c_separator(cl[i])
			|| is_c_redirection(cl[i])))
	    check = check_following_chars(cl + i);
	  else if (i == 0 && is_c_separator(cl[i]))
	    check = 0;
	}
      else
	check = 0;
      i++;
    }
  return (check);
}
