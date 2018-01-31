/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 22:10:06 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/mysh.h"
#include "include/mystr.h"

int	wordtab_size(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab && wordtab[i])
    i++;
  return (i);
}

void	free_wordtab(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab && wordtab[i])
    {
      free(wordtab[i]);
      i++;
    }
  if (wordtab)
    free(wordtab);
}

static int	copy_wordtab(char **dest, int k,
			     char **insert, int rows)
{
  int		j;

  j = 0;
  while (insert[j] && k < rows)
    {
      dest[k] = my_strdup(insert[j]);
      k++;
      j++;
    }
  return (k);
}

char	**insert_wordtab_after_elem(char **wordtab,
				    char **insert, int elem)
{
  int	i;
  int	k;
  int	rows;
  char	**dest;

  rows = wordtab_size(wordtab) - 1 + wordtab_size(insert) + 1;
  if ((dest = malloc(rows * sizeof(*dest))) == NULL)
    return (NULL);
  k = 0;
  i = 0;
  while (wordtab && wordtab[i] && i < elem && k < rows)
    {
      dest[k] = my_strdup(wordtab[i]);
      k++;
      i++;
    }
  k = copy_wordtab(dest, k, insert, rows);
  while (wordtab && wordtab[++i] && k < rows)
    {
      dest[k] = my_strdup(wordtab[i]);
      k++;
    }
  dest[k] = NULL;
  return (dest);
}

char	**wtab_remove_one_line(char **wordtab, int elem)
{
  int	i;

  i = elem;
  while (wordtab && wordtab[i])
    {
      wordtab[i] = wordtab[i + 1];
      i++;
    }
  return (NULL);
}
