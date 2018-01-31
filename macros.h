/*
** mysh.h for m0ysh in /home/buchse_a/Documents/PSU_2013_minishell1
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Wed Dec  4 13:07:31 2013 Antoine Buchser
** Last update Sat May 24 13:38:25 2014 Antoine Buchser
*/

#ifndef MACROS_H_
# define MACROS_H_

# define XSIGNAL(n, h)	if (signal(n, h) == SIG_ERR) return (my_perror(NULL))
# define XWPID(p, s)	if (waitpid(p, s, 0) == -1) return (my_perror(NULL))

#endif /* !MACROS_H_ */
