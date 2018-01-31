/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 22:00:56 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/mysh.h"
#include "include/myprintf.h"
#include "include/mystr.h"

void	my_error(char *str)
{
  if (str != NULL)
    {
      write_error(str);
      my_putchar('\n');
    }
  exit(EXIT_FAILURE);
}

static void	fill_concat3(char *dest, char *string, int *j)
{
  int		i;

  i = 0;
  while (string[i])
    {
      dest[*j] = string[i];
      i++;
      *j = *j + 1;
    }
}

char	*my_concat3(char *s1, char *s2, char *s3)
{
  char	*strings[3];
  char	*dest;
  int	j;
  int	k;

  strings[0] = s1;
  strings[1] = s2;
  strings[2] = s3;
  if ((dest = malloc((my_strlen(s1) + my_strlen(s2) + my_strlen(s3) + 1)
		     * sizeof(*dest))) == NULL)
    {
      my_perror(NULL);
      return (NULL);
    }
  j = 0;
  k = 0;
  while (k < 3)
    {
      fill_concat3(dest, strings[k], &j);
      k++;
    }
  dest[j] = '\0';
  return (dest);
}
