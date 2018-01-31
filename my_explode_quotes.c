/*
** my_strcat.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:38:55 2014 Antoine Buchser
** Last update Wed May 21 12:07:23 2014 Antoine Buchser
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int	count_words(char **wtab)
{
  int		i;
  int		words;

  words = 0;
  i = -1;
  while (wtab[++i])
    words++;
  i = -1;
  while (wtab[++i])
    if (!my_strcmp(wtab[i], "\""))
      {
	words--;
	if (!my_strcmp(wtab[i + 1], "\""))
	  words--;
	while (my_strcmp(wtab[++i], "\""))
	  words--;
      }
  return (words);
}

static void	my_explode_fill_line(int *i, char **wtab,
				     int *j, char **dest)
{
  char		*tmp;
  char		*rm;

  tmp = NULL;
  (*i)++;
  if (my_strcmp(wtab[*i], "\""))
    {
      tmp = my_strdup(wtab[*i]);
      (*i)++;
      while (wtab[*i] && my_strcmp(wtab[*i], "\""))
	{
	  rm = tmp;
	  tmp = my_concat3(tmp, " ", wtab[*i]);
	  free(rm);
	  (*i)++;
	}
      if (tmp && tmp[my_strlen(tmp) - 1] == ' ')
	tmp[my_strlen(tmp) - 1] = '\0';
    }
  if (tmp)
    dest[++(*j)] = tmp;
}

char	**my_explode_quotes(char *str)
{
  char	**wtab;
  char	**dest;
  int	words_nb;
  int	i;
  int	j;

  wtab = my_str_to_wordtab(str);
  words_nb = count_words(wtab);
  if (!(dest = malloc((words_nb + 1) * sizeof(*dest))))
    return (NULL);
  i = -1;
  j = -1;
  while (wtab && wtab[++i] && j < words_nb)
    {
      if (!my_strcmp(wtab[i], "\""))
	my_explode_fill_line(&i, wtab, &j, dest);
      else
	dest[++j] = my_strdup(wtab[i]);
    }
  dest[words_nb] = NULL;
  free_wordtab(wtab);
  return (dest);
}
