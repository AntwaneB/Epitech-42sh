/*
** mini.h for minilib in /home/buchse_a/Documents/Lib
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Mar 20 17:14:26 2014 Antoine Buchser
** Last update Thu Mar 20 18:33:37 2014 Antoine Buchser
*/

#ifndef MINI_H_
# define MINI_H_

void	my_putchar(char);
void	my_putnbr(long);
void	my_putstr(char*);
int	my_strlen(char*);
long	my_getnbr(char*);
int	my_strcmp(char*, char*);
int	my_strncmp(char*, char*, int);
char	*my_strcat(char*, char*);
char	*my_strdup(char*);
char	*my_strndup(char*, int);
void	my_putnbr_base(long, char*);
int	my_getnbr_base(char*, char*);
char	**my_explode(char*);

#endif /* !MINI_H_ */
