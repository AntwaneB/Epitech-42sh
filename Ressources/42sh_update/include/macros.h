/*
** mysh.h for m0ysh in /home/buchse_a/Documents/PSU_2013_minishell1
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Wed Dec  4 13:07:31 2013 Antoine Buchser
** Last update Mon May  5 10:09:40 2014 Antoine Buchser
*/

#ifndef MACROS_H_
# define MACROS_H_

# define XSIGNAL(n, h)	if (signal(n, h) == SIG_ERR) return (my_perror(NULL))
# define IS_SPACE(c)	((c == ' ' || c == '\t') ? 1 : 0)

#endif /* !MACROS_H_ */
