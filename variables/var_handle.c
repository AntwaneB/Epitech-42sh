/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:02:22 2014 Antoine Buchser
*/

#include "../my.h"
#include "../mysh.h"

static int	var_replace_variable(t_sh *sh, char **cl,
				     char ***cl_ptr, int *i)
{
  char		**insert;

  if (cl[*i] && cl[*i][0] == '$' && cl[*i][1]
      && var_exists(sh->var_list, cl[*i] + 1)
      && var_get_value(sh->var_list, cl[*i] + 1))
    {
      insert = my_str_to_wordtab(var_get_value(sh->var_list, cl[*i] + 1));
      *cl_ptr = insert_wordtab_after_elem(cl, insert, *i);
      *i += wordtab_size(insert) - 1;
      free_wordtab(insert);
      free_wordtab(cl);
      return ((*cl_ptr == NULL) ? -1 : 0);
    }
  else if (cl[*i] && cl[*i][0] == '$' && cl[*i][1]
	   && env_var_exists(sh->env_list, cl[*i] + 1)
	   && env_get_value_from_list(sh->env_list, cl[*i] + 1))
    {
      insert = my_str_to_wordtab(env_get_value_from_list(sh->env_list,
							 cl[*i] + 1));
      *cl_ptr = insert_wordtab_after_elem(cl, insert, *i);
      *i += wordtab_size(insert) - 1;
      free_wordtab(cl);
      return ((*cl_ptr == NULL) ? -1 : 0);
    }
  return (0);
}

int	var_handle(t_sh *sh, t_cl *cmd)
{
  int	i;

  i = 0;
  while (cmd->cl && cmd->cl[i])
    {
      var_replace_variable(sh, cmd->cl, &(cmd->cl), &i);
      i++;
    }
  return (0);
}
