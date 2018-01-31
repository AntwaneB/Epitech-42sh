/*
** my_realloc.c for my_realloc in /home/schoch_h/Projets/my_ls
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Sun Dec  1 20:31:00 2013 SCHOCH Hugo
** Last update Thu May  8 14:37:48 2014 Hugo Schoch
*/

#include <stdlib.h>
#include "../../include/mystr.h"

char	**my_realloc_tab(char **tab, int size)
{
  char	**res;
  int	length;
  int	pos;

  pos = 0;
  length = my_tab_strlen(tab) + size + 1;
  if ((res = malloc(length + sizeof(*res))) == NULL)
    return (NULL);
  while (tab[pos] != NULL)
    {
      res[pos] = my_strdup(tab[pos]);
      pos++;
    }
  res[length - 1] = NULL;
  return (res);
}


char	*my_realloc(char *str, int size)
{
  char	*tmp;

  tmp = malloc((my_strlen(str) + 1) * sizeof(*tmp));
  if (tmp == NULL)
    return (0);
  my_strcpy(tmp, str);
  free(str);
  str = malloc((my_strlen(tmp) + size) * sizeof(*str));
  if (str == NULL)
    return (0);
  my_strcpy(str, tmp);
  free(tmp);
  return (str);
}
