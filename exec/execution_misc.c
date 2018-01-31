/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 13:20:04 2014 Thomas MORITZ
*/

#include <unistd.h>

void	reset_pipefds(int *pipefds)
{
  pipefds[0] = 0;
  pipefds[1] = 1;
}

void	close_pipefds(int fd, int std)
{
  if (fd != std)
    {
      close(fd);
    }
}
