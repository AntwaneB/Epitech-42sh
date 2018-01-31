##
## Makefile for libmy.a in /home/schoch_h/Piscine/Piscine-C-lib/my
## 
## Made by SCHOCH Hugo
## Login   <schoch_h@epitech.net>
## 
## Started on  Mon Oct 21 10:21:18 2013 SCHOCH Hugo
## Last update Fri May  9 23:10:48 2014 Hugo Schoch
##

RM	=	rm -rf

NAME	=	../libmynbr.a

HEADER	=	../../include/mynbr.h

SRCS	=	my_getnbr_base.c \
		my_getnbr.c \
		my_pow.c

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
