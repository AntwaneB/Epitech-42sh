/*
** my.h for my in /home/schoch_h/Piscine/Piscine-C-include
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Thu Oct 10 09:42:20 2013 SCHOCH Hugo
** Last update Fri May  9 23:22:39 2014 Hugo Schoch
*/

#ifdef MY_STR_

# include "mystr.h"

#endif

#ifndef MY_PRINTF_
# define MY_PRINTF_

void	my_putchar(char);
int	my_put_nbr(int);
void	my_putstr(char*);
int	my_showstr(char*);
void	my_show_wordtab(char**);
int	my_putnbr_base(int, char*);
int	my_printf(char*, ...);
int	my_putnbr_base_unsigned(unsigned int, char*);
int	my_put_nbr_unsigned(unsigned int);
int	my_showstr_octal(char*);
void	my_show_wordtab_octal(char**);

#endif /* !MY_PRINTF_ */
