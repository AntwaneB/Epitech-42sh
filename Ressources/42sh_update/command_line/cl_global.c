/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 22:14:09 2014 Hugo Schoch
*/

#include <stdlib.h>
#include "../include/mysh.h"
#include "../include/mystr.h"

int	is_c_separator(char c)
{
  if (c == ';' || c == '|')
    return (1);
  else
    return (0);
}

int	is_separator(char *str)
{
  if (str[0] == str[1]
      && (str[0] == '&' || str[0] == '|'))
    return (2);
  else if (str[0] == '|' || str[0] == ';')
    return (1);
  else
    return (0);
}

int	is_c_redirection(char c)
{
return ((c == '>' || c == '<') ? 1 : 0);
}

int	is_redirection_len(char *str)
{
  if (my_strncmp(str, ">>", 2) == 0 || my_strncmp(str, "<<", 2) == 0)
    return (2);
  else if ((str[0] == '>' && str[1] != '>') ||
	   (str[0] == '<' && str[1] != '<'))
    return (1);
  else
    return (0);
}

int	is_redirection(char *str)
{
  if (my_strncmp(str, ">>", 2) == 0 || (str[0] == '>' && str[1] != '>'))
    return (2);
  else if (my_strncmp(str, "<<", 2) == 0
	   || (str[0] == '<' && str[1] != '<'))
    return (1);
  else
    return (0);
}

char	*get_separator(char *str)
{
  char	*dest;

  if (is_separator(str) == 2)
    {
      if ((dest = malloc(3 * sizeof(char))) == NULL)
	{
	  my_perror(NULL);
	  return (NULL);
	}
      dest[0] = str[0];
      dest[1] = str[1];
      dest[2] = '\0';
    }
  else
    {
      if ((dest = malloc(2 * sizeof(char))) == NULL)
	{
	  my_perror(NULL);
	  return (NULL);
	}
      dest[0] = str[0];
      dest[1] = '\0';
    }
  return (dest);
}
