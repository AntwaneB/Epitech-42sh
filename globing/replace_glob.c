/*
** replace_glob.c for glob in /home/giubil_v
**
** Made by victor giubilei
** Login   <giubil_v@epitech.net>
**
** Started on  Wed May  7 13:02:51 2014 victor giubilei
** Last update Sat May 24 12:40:39 2014 Thomas MORITZ
*/

#include <glob.h>
#include "../mysh.h"

static int	replace_glob(char ***args)
{
  int		i;
  glob_t	globbuf;
  int		return_value;

  i = -1;
  while ((*args)[++i])
    {
      return_value = glob((*args)[i], 0, NULL, &globbuf);
      if (return_value != GLOB_NOMATCH && !(return_value))
	{
	  if (!(*args = insert_wordtab_after_elem(*args, globbuf.gl_pathv, i)))
	    return (my_perror("Malloc failed"));
	}
      else if (return_value != GLOB_NOMATCH && return_value)
	return (my_perror(NULL));
    }
  globfree(&globbuf);
  return (0);
}

int	glob_handle(t_clm *cl)
{
  t_cl	*command;

  command = cl->first;
  while (command)
    {
      if (replace_glob(&(command->cl)))
	return (-1);
      command = command->next;
    }
  return (0);
}
