/*
** print_prompt.c for print_prompt in /home/giubil_v
**
** Made by victor giubilei
** Login   <giubil_v@epitech.net>
**
** Started on  Fri May 16 13:07:23 2014 victor giubilei
** Last update Sat May 24 13:01:47 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../my.h"
#include "../mysh.h"

static char	*get_path_value(char *name, t_env *env)
{
  while (env)
    {
      if (!(strcmp(name, env->name)))
	return (env->value);
      env = env->next;
    }
  return (NULL);
}

static void	replace_home(char *path, t_env *env)
{
  char		*home;

  if (!(home = get_path_value("HOME", env)))
    return ;
  if (!(strncmp(path, home, strlen(home))))
    sprintf(path, "~%s", path + strlen(home));
}

static int	check_path_depth(char **path, char **save, t_env *env)
{
  int		last;
  int		count;
  int		prompt_depth;
  char		*prompt_depth_buffer;

  if ((prompt_depth_buffer = get_path_value("PROMPT_DEPTH", env)))
    prompt_depth = my_getnbr(prompt_depth_buffer);
  else
    prompt_depth = PROMPT_DEPTH;
  *save = *path;
  last = strlen(*path);
  count = 0;
  while (--last && count < prompt_depth)
    if ((*path)[last] == '/')
      count++;
  if (count < prompt_depth)
    return (0);
  *path += last + 1;
  return (1);
}

static int	write_prompt(char *user, char **path,
			     char color, char **old_path)
{
  t_sh		*sh;
  int		length;

  sh = backup_sh(NULL, 1);
  write(1, "\033[3", 3);
  write(1, &color, 1);
  write(1, "m", 1);
  write(1, user, strlen(user));
  write(1, " @ ", 3);
  length = 0;
  if (check_path_depth(path, old_path, sh->env_list))
    {
      length = 3;
      write(1, "...", 3);
    }
  write(1, *path, strlen(*path));
  length += 5 + strlen(user) + strlen(*path);
  my_putstr("$\033[0m ");
  return (length);
}

int		print_prompt(void)
{
  char		*user;
  char		*old_path;
  char		*path;
  char		color;
  t_sh		*sh;
  int		length;

  sh = backup_sh(NULL, 1);
  if (!(get_path_value("PROMPT_COLOR", sh->env_list)))
    color = rand() % 6 + '1';
  else
    color = get_path_value("PROMPT_COLOR", sh->env_list)[0];
  user = get_path_value("USER", sh->env_list);
  old_path = get_path_value("PWD", sh->env_list);
  user = (!user) ? "smurf" : user;
  old_path = (!old_path) ? "nowhere" : old_path;
  if (!(path = malloc((strlen(old_path) + 1) * sizeof(char))))
    return (-1);
  strcpy(path, old_path);
  if (strlen(user) <= 32)
    replace_home(path, sh->env_list);
  length = write_prompt(user, &path, color, &old_path);
  free(old_path);
  return (length);
}
