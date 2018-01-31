/*
** my_strcat.c for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:38:55 2014 Antoine Buchser
** Last update Thu May  8 22:10:18 2014 Hugo Schoch
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/mysh.h"
#include "include/mystr.h"

static int	is_space(char c)
{
  return (c == ' ' || c == '\t');
}

static int	count_words(char **wtab)
{
  int		i;
  int		j;
  int		words;
  int		jmp;

  jmp = -1;
  words = 0;
  i = -1;
  while (wtab[++i])
    words++;
  i = -1;
  while (wtab[++i])
    if (wtab[i][0] == '"' && i != jmp &&
	wtab[i][my_strlen(wtab[i]) -1] != '"')
      {
	j = i;
	while (wtab[++j] && wtab[j][my_strlen(wtab[j]) - 1] != '"')
	  words--;
	jmp = (wtab[j] && !my_strcmp(wtab[j], "\"")) ? j : -1;
	words--;
      }
  return (words);
}

static int	my_explode_fill_line(int *i, int *j,
				     char **wtab, char **dest)
{
  char		*tmp;

  *i = (!my_strcmp(wtab[*i], "\"")) ? *i + 1 : *i;
  dest[++(*j)] = my_strdup(((wtab[*i][0] == '"') ? wtab[*i] + 1 : wtab[*i]));
  *i = (wtab[*i][my_strlen(wtab[*i]) - 1] != '"') ? *i + 1 : *i;
  while (wtab[*i] && wtab[*i][my_strlen(wtab[*i]) - 1] != '"')
    {
      tmp = dest[*j];
      dest[*j] = my_concat3(tmp, " ", wtab[*i]);
      free(tmp);
      (*i)++;
    }
  if (wtab[*i] && wtab[*i][my_strlen(wtab[*i]) - 1] == '"'
      && my_strcmp(wtab[*i], "\"") && wtab[*i][0] != '"')
    {
      tmp = dest[*j];
      dest[*j] = my_concat3(tmp, " ", wtab[*i]);
      free(tmp);
    }
  if (dest[*j][my_strlen(dest[*j]) - 1] == '"')
    dest[*j][my_strlen(dest[*j]) - 1] = '\0';
  return ((wtab[*i] && !my_strcmp(wtab[*i - 1], "\"")) ? *i : -1);
}

char	**my_explode_quotes(char *str)
{
  char	**wtab;
  char	**dest;
  int	words_nb;
  int	i;
  int	j;
  int	jmp;

  wtab = my_str_to_wordtab(str);
  words_nb = count_words(wtab);
  if (!(dest = malloc((words_nb + 1) * sizeof(*dest))))
    return (NULL);
  i = -1;
  jmp = -1;
  j = -1;
  while (wtab && wtab[++i] && j < words_nb)
    {
      if (wtab[i][0] != '"')
	dest[++j] = my_strdup(wtab[i]);
      else if (wtab[i][0] == '"' && i != jmp)
	jmp = my_explode_fill_line(&i, &j, wtab, dest);
    }
  dest[words_nb] = NULL;
  free_wordtab(wtab);
  return (dest);
}
