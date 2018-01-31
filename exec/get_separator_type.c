/*
** get_separator_type.c for kakarante-deux sh in /home/buchse_a/Documents/43sh/exec
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Wed Apr 30 16:37:59 2014 Antoine Buchser
** Last update Sat May 24 13:20:45 2014 Thomas MORITZ
*/

#include "../my.h"

int	is_pipe(char *separator)
{
  if (separator && !my_strcmp(separator, "|"))
    return (1);
  else
    return (0);
}

int	is_and(char *separator)
{
  if (separator && !my_strcmp(separator, "&&"))
    return (1);
  else
    return (0);
}

int	is_or(char *separator)
{
  if (separator && !my_strcmp(separator, "||"))
    return (1);
  else
    return (0);
}

int	is_semicol(char *separator)
{
  if (separator && !my_strcmp(separator, ";"))
    return (1);
  else
    return (0);
}

