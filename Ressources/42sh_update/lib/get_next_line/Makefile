##
## Makefile for get_next_line in /home/schoch_h/Projets/42sh_update/Lib/get_next_line
## 
## Made by Hugo Schoch
## Login   <schoch_h@epitech.net>
## 
## Started on  Thu May  8 14:03:40 2014 Hugo Schoch
## Last update Thu May  8 14:16:23 2014 Hugo Schoch
##

RM		=	rm -f

NAME		=	../libgnl.a

HEADER		=	../get_next_line.h

SRCS		=	get_next_line.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
