##
## Makefile for do-op in /home/buchse_a/Documents/Piscine-C-lib/my
##
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
##
## Started on  Mon Oct 21 09:30:31 2013 Antoine Buchser
## Last update Thu Mar 20 18:35:10 2014 Antoine Buchser
##

RM		=	rm -f
CC		=	cc
NAME		=	mini
CFLAGS		=	-Wall -Wextra -g

SRCS		=	main.c \
			my_putchar.c \
			my_putnbr.c \
			my_putstr.c \
			my_strlen.c \
			my_getnbr.c \
			my_strcmp.c \
			my_strncmp.c \
			my_strcat.c \
			my_strdup.c \
			my_strndup.c \
			my_putnbr_base.c \
			my_getnbr_base.c \
			my_explode.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

#libmini.a:	$(OBJS)
#		ar rc lib$(NAME).a $(OBJS)
#		ranlib lib$(NAME).a

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.SILENT:
