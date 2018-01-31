##
## Makefile for do-op in /home/buchse_a/Documents/Piscine-C-lib/my
##
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
##
## Started on  Mon Oct 21 09:30:31 2013 Antoine Buchser
## Last update Sat May 24 14:06:25 2014 Antoine Buchser
##

LIB_DIR		=	./libmy

RM		=	rm -f
CC		=	cc
NAME		=	mysh

SRCS		=	main.c \
			command_line/cl_global.c \
			command_line/cl_global2.c \
			command_line/cl_to_list.c \
			command_line/cl_to_list2.c \
			command_line/cl_handle_env_rm.c \
			command_line/cl_lists.c \
			command_line/cl_is_valid.c \
			command_line/cl_free.c \
			command_line/cl_handle.c \
			command_line/epur_command_line.c \
			environment/env_lists.c \
			environment/env_lists2.c \
			environment/env_to_list.c \
			environment/env_list_to_tab.c \
			path/path_to_tab.c \
			path/path_global.c \
			exec/execute_cmd.c \
			exec/execute_pipeline.c \
			exec/execution_misc.c \
			exec/my_execve.c \
			exec/double_left.c \
			exec/print_wait_status.c \
			exec/get_separator_type.c \
			exec/execute_type.c \
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
			builtins/handle_echo_spe.c \
			builtins/handle_unset.c \
			builtins/handle_set.c \
			builtins/handle_history.c \
			alias/ali_handle.c \
			alias/ali_lists.c \
			alias/ali_lists_free.c \
			variables/var_handle.c \
			variables/var_lists.c \
			variables/var_lists_free.c \
			variables/is_variable.c \
			variables/var_create.c \
			termcap/history.c \
			termcap/my_key.c \
			termcap/terminal.c \
			termcap/windows.c \
			termcap/init.c \
			autocomplete/add.c \
			autocomplete/autocomplete.c \
			autocomplete/initialisation.c \
			history/hist_lists.c \
			globing/replace_glob.c \
			prompt/print_prompt.c \
			misc.c \
			errors.c \
			wordtab.c \
			my_explode_quotes.c

OBJS		=	$(SRCS:.c=.o)

all:			./libmy/libmy.a $(NAME)

./libmy/libmy.a:
			make -C $(LIB_DIR)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -lmy -L$(LIB_DIR) -lncurses

clean:
			make clean -C $(LIB_DIR)
			$(RM) $(OBJS)

fclean:			clean
			make fclean -C $(LIB_DIR)
			$(RM) $(NAME)

re:			fclean all
