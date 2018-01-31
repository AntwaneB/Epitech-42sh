##
## Makefile for do-op in /home/buchse_a/Documents/Piscine-C-lib/my
##
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
##
## Started on  Mon Oct 21 09:30:31 2013 Antoine Buchser
## Last update Thu May  8 23:11:49 2014 Hugo Schoch
##

RM		=	rm -f

CC		=	cc

NAME		=	mysh

LIB		=	-Llib/ -lgnl -lmystr -lmynbr -lmyprintf

CFLAGS		=	-Wall -Wextra -g -Wshadow -Wundef
CFLAGS		+=	-Wno-unused-variable
CFLAGS		+=	-Wno-unused-parameter
CFLAGS		+=	-Wno-unused-function

SRCS		=	main.c \
			command_line/cl_global.c \
			command_line/cl_to_list.c \
			command_line/cl_redir.c \
			command_line/cl_handle_env_rm.c \
			command_line/cl_lists.c \
			command_line/cl_is_valid.c \
			command_line/cl_free.c \
			command_line/cl_handle.c \
			command_line/epur_command_line.c \
			environment/env_data.c \
			environment/env_infos.c \
			environment/env_to_list.c \
			environment/env_list_to_tab.c \
			path/path_to_tab.c \
			path/path_global.c \
			exec/my_execve.c \
			exec/my_exec_father.c \
			exec/get_fds.c \
			exec/count_pipes.c \
			exec/double_left.c \
			exec/print_wait_status.c \
			builtins/is_builtin.c \
			builtins/handle_builtin.c \
			builtins/handle_exit.c \
			builtins/handle_unsetenv.c \
			builtins/handle_setenv.c \
			builtins/handle_env.c \
			builtins/handle_cd.c \
			builtins/handle_alias.c \
			builtins/handle_unalias.c \
			builtins/handle_echo.c \
			builtins/handle_unset.c \
			alias/ali_handle.c \
			alias/ali_lists.c \
			alias/ali_remove.c \
			variables/var_handle.c \
			variables/var_lists.c \
			variables/var_remove.c \
			variables/is_variable.c \
			variables/var_create.c \
			termcap/history.c \
			termcap/my_key.c \
			termcap/terminal.c \
			termcap/windows.c \
			misc.c \
			errors.c \
			wordtab.c \
			my_explode_quotes.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB) -lncurses

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.SILENT:
