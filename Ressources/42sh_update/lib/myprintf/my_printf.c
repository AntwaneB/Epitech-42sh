/*
** my_printf.c for my_printf in /home/schoch_h/Projets/my_printf
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Wed Nov 13 19:00:18 2013 SCHOCH Hugo
** Last update Fri May  9 23:24:49 2014 Hugo Schoch
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../../include/myprintf.h"

static void	my_printf_flags(char *flags_tab)
{
  char		*flags;
  int		pos;

  pos = 0;
  flags = malloc(12 * sizeof(*flags));
  flags = "dicspuxXobStT%";
  while (pos <= my_strlen_printf(flags))
    {
      flags_tab[pos] = flags[pos];
      pos = pos + 1;
    }
  free(flags);
}

static int	check_flags_bis(char flag, int pos, va_list ap)
{
  if (flag == 'x')
    my_putnbr_base_unsigned(va_arg(ap, unsigned int), "0123456789abcdef");
  else if (flag == 'X')
    my_putnbr_base_unsigned(va_arg(ap, unsigned int), "0123456789ABCDEF");
  else if (flag == 'o')
    my_putnbr_base_unsigned(va_arg(ap, unsigned int), "01234567");
  else if (flag == 'b')
    my_putnbr_base_unsigned(va_arg(ap, unsigned int), "01");
  else if (flag == 'S')
    my_showstr_octal(va_arg(ap, char*));
  else if (flag == 't')
    my_show_wordtab(va_arg(ap, char**));
  else if (flag == 'T')
    my_show_wordtab_octal(va_arg(ap, char **));
  else if (flag == '%')
    my_putchar('%');
  return (pos);
}

static int	check_flags(char *str, int pos, va_list ap)
{
  char		flag;

  pos = pos + 1;
  flag = str[pos];
  if (flag == 'd' || flag == 'i')
    my_put_nbr(va_arg(ap, int));
  else if (flag == 'c')
    my_putchar(va_arg(ap, int));
  else if (flag == 's')
    my_putstr(va_arg(ap, char*));
  else if (flag == 'p')
    my_put_nbr((va_arg(ap, int)));
  else if (flag == 'u')
    my_put_nbr_unsigned(va_arg(ap, unsigned int));
  else
    pos = check_flags_bis(flag, pos, ap);
  return (pos);
}

int	my_printf(char *str, ...)
{
  va_list	ap;
  int		pos;

  pos = 0;
  va_start(ap, str);
  while (str[pos] != '\0')
    {
      if (str[pos] == '%')
	pos = check_flags(str, pos, ap);
      else
	my_putchar(str[pos]);
      pos = pos + 1;
    }
  va_end(ap);
  return (pos);
}
