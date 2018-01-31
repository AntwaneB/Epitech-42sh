/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Thu May  8 22:09:53 2014 Hugo Schoch
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "include/mysh.h"
#include "include/myprintf.h"

void	write_error(char *str)
{
  if (str)
    write(2, str, my_strlen(str));
}

void	formated_error(char *cmd, char *msg)
{
  write_error(cmd);
  write_error(": ");
  write_error(msg);
  write_error("\n");
}

int	my_perror(char *str)
{
  if (str)
    write_error(str);
  else
    write_error(strerror(errno));
  my_putchar('\n');
  return (-1);
}
