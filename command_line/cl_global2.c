/*
** main.c for mysh2 in /home/buchse_a/Documents/PSU_2013_minishell2/v2
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Feb  6 13:11:17 2014 Antoine Buchser
** Last update Sat May 24 12:47:24 2014 Thomas MORITZ
*/

int	is_c_separator(char c)
{
  if (c == ';' || c == '|' || c == '&')
    return (1);
  else
    return (0);
}
