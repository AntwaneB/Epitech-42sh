##
## Makefile for libmy Makefile in /home/buchse_a/Documents/Piscine-C-lib/my
##
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
##
## Started on  Mon Oct 21 09:30:31 2013 Antoine Buchser
## Last update Mon May 19 11:20:07 2014 Antoine Buchser
##

LIB_DIR		=	.

RM		=	rm -f

NAME		=	my

SRCS		=	$(LIB_DIR)/my_getnbr_base.c \
			$(LIB_DIR)/my_getnbr.c \
			$(LIB_DIR)/my_putchar.c \
			$(LIB_DIR)/my_putnbr_base.c \
			$(LIB_DIR)/my_put_nbr.c \
			$(LIB_DIR)/my_putstr.c \
			$(LIB_DIR)/my_showstr.c \
			$(LIB_DIR)/my_strcat.c \
			$(LIB_DIR)/my_strcmp.c \
			$(LIB_DIR)/my_strcpy.c \
			$(LIB_DIR)/my_strdup.c \
			$(LIB_DIR)/my_strndup.c \
			$(LIB_DIR)/my_str_isalpha.c \
			$(LIB_DIR)/my_str_isnum.c \
			$(LIB_DIR)/my_str_isprintable.c \
			$(LIB_DIR)/my_strlen.c \
			$(LIB_DIR)/my_strlowcase.c \
			$(LIB_DIR)/my_strncat.c \
			$(LIB_DIR)/my_strncmp.c \
			$(LIB_DIR)/my_strncpy.c \
			$(LIB_DIR)/my_strstr.c \
			$(LIB_DIR)/my_str_to_wordtab.c \
			$(LIB_DIR)/my_strupcase.c \
			$(LIB_DIR)/my_putposnbr_base.c \
			$(LIB_DIR)/my_putunnbr_base.c \
			$(LIB_DIR)/my_putlongnbr_base.c \
			$(LIB_DIR)/my_put_unnbr.c \
			$(LIB_DIR)/my_printf_special_modifiers.c \
			$(LIB_DIR)/my_printf_h_modifiers.c \
			$(LIB_DIR)/my_printf_string_func.c \
			$(LIB_DIR)/my_printf.c \
			$(LIB_DIR)/get_next_line.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	libmy.a

libmy.a:	$(OBJS)
		ar rc lib$(NAME).a $(OBJS)
		ranlib lib$(NAME).a

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(LIB_DIR)/lib$(NAME).a

re:		fclean all
