/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:55:56 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <strings.h>
#include "../my.h"

static int	is_space(char c)
{
  return ((c == ' ' || c == '\t') ? 1 : 0);
}

static int	is_redorsep(char *str)
{
  if (my_strlen(str) >= 2 && str[0] == str[1]
      && (str[0] == '|' || str[0] == '&'
	  || str[0] == '>' || str[0] == '<'))
    return (2);
  else if (str[0] == '|' || str[0] == '>'
	   || str[0] == '<' || str[0] == '=' || str[0] == '"')
    return (1);
  else
    return (0);
}

static int	count_chars(char *str)
{
  int		i;
  int		chars;

  chars = 0;
  i = 0;
  while (str && str[i])
    {
      if (!is_space(str[i]) && !is_redorsep(str + i))
	chars++;
      else if (is_redorsep(str + i))
	{
	  if (i > 0 && !is_space(str[i - 1]))
	    chars++;
	  chars += is_redorsep(str + i);
	  i = (is_redorsep(str + i) == 2) ? i + 1 : i;
	  if (str[i + 1] != '\0' && !is_space(str[i + 1]))
	    chars++;
	}
      else if (i > 0 && is_space(str[i])
	       && !is_space(str[i - 1]))
	chars++;
      i++;
    }
  chars = (i > 0 && is_space(str[i - 1])) ? chars - 1 : chars;
  return (chars);
}

void	write_redorsep(char *str, char *dest, int *i, int *j)
{
  if (*j >= 0 && !is_space(dest[*j]))
    dest[++(*j)] = ' ';
  dest[++(*j)] = str[*i];
  if (is_redorsep(str + *i) == 2)
    dest[++(*j)] = str[*i + 1];
  *i = (is_redorsep(str + *i) == 2) ? *i + 1 : *i;
  if (str[*i + 1] != '\0' && !is_space(str[*i + 1]))
    dest[++(*j)] = ' ';
}

char	*epur_command_line(char *str)
{
  char	*dest;
  int	i;
  int	j;
  int	strlen;

  strlen = count_chars(str);
  if ((dest = malloc((strlen + 1) * sizeof(dest))) == NULL)
    return (NULL);
  bzero(dest, strlen + 1);
  j = -1;
  i = -1;
  while (str && str[++i] && j < strlen)
    {
      if (!is_space(str[i]) && !is_redorsep(str + i))
	dest[++j] = str[i];
      else if (is_redorsep(str + i))
	write_redorsep(str, dest, &i, &j);
      else if (i > 0 && is_space(str[i])
	       && !is_space(str[i - 1]))
	dest[++j] = ' ';
    }
  dest[(i > 0 && is_space(str[i - 1])) ? j : j + 1] = '\0';
  free(str);
  return (dest);
}
