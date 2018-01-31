##
## Makefile for libmy.a in /home/schoch_h/Piscine/Piscine-C-lib/my
## 
## Made by SCHOCH Hugo
## Login   <schoch_h@epitech.net>
## 
## Started on  Mon Oct 21 10:21:18 2013 SCHOCH Hugo
## Last update Fri May  9 23:17:16 2014 Hugo Schoch
##

RM	=	rm -rf

NAME	=	../libmystr.a

HEADER	=	../../include/mystr.h

SRCS	=	my_realloc.c \
		my_revstr.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strncat.c \
		my_strncmp.c \
		my_strndup.c \
		my_str_insert.c \
		my_strlen.c \
		my_explode.c \
		my_str_to_wordtab.c

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
