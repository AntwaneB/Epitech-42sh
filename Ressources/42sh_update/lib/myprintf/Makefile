##
## Makefile for libmy.a in /home/schoch_h/Piscine/Piscine-C-lib/my
## 
## Made by SCHOCH Hugo
## Login   <schoch_h@epitech.net>
## 
## Started on  Mon Oct 21 10:21:18 2013 SCHOCH Hugo
## Last update Thu May  8 14:17:20 2014 Hugo Schoch
##

RM	=	rm -rf

NAME	=	../libmyprintf.a

HEADER	=	../myprintf.h

SRCS	=	my_printf.c \
		my_putchar.c \
		my_putnbr_base.c \
		my_putnbr_base_unsigned.c \
		my_put_nbr.c \
		my_put_nbr_unsigned.c \
		my_putstr.c \
		my_showstr.c \
		my_showstr_octal.c \
		my_show_wordtab.c \
		my_strlen.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
