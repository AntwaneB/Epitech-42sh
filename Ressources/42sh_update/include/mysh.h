/*
** mysh.h for m0ysh in /home/buchse_a/Documents/PSU_2013_minishell1
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Wed Dec  4 13:07:31 2013 Antoine Buchser
** Last update Wed Apr 30 14:34:59 2014 Antoine Buchser
*/

#ifndef MYSH_H_
# define MYSH_H_

# include <unistd.h>
# include <term.h>

# define PROMPT "\033[36msmurf@shell$\033[0m "

typedef struct termios	termios;

typedef struct	s_cl
{
  char		**cl;
  char		*separator;
  char		*readfrom;
  char		readtype;
  char		*writeto;
  char		writetype;
  int		env;
  int		status;
  pid_t		pgid;
  struct s_cl	*next;
  struct s_cl	*prev;
}		t_cl;

typedef struct	s_clm
{
  t_cl		*first;
  t_cl		*last;
}		 t_clm;

typedef struct	s_env
{
  char		*name;
  char		*value;
  struct s_env	*next;
}		 t_env;

typedef struct	s_var
{
  char		*name;
  char		*value;
  struct s_var	*next;
}		t_var;

typedef struct	s_ali
{
  char		*name;
  char		*value;
  struct s_ali	*next;
}		t_ali;

typedef struct	s_coor
{
  int           max_x;
  int           max_y;
  int           x;
  int           y;
  int           save_x;
  int           save_y;
  int           pos_x;
  int           pos_y;
}		t_coor;

typedef struct	s_sh
{
  t_clm		*cl;
  t_env		*env_list;
  t_var		*var_list;
  t_ali		*alias_list;
  char		**env_tab;
  char		**path_tab;
  char		**history;
  termios	backup;
  pid_t		pgid;
  pid_t		pid;
}		 t_sh;

typedef struct	s_pid
{
  int		pid;
  int		input;
}		t_pid;

typedef struct	s_ldr
{
  char		*line;
  struct s_ldr	*next;
}		t_ldr;

t_sh	*backup_sh(t_sh*, int);

int	is_separator(char*);
int	is_c_separator(char);
int	is_redirection(char*);
int	is_c_redirection(char);
int	is_redirection_len(char*);
char	*get_separator(char*);
int	cl_to_list(t_clm*, char*);
int	cl_put_in_list(t_clm*, char**, char*);
int	cl_is_valid(char*);
void	cl_free(t_clm*);
int	cl_handle(t_sh*, t_clm*);
void	cl_handle_env_rm(t_clm*);
char	*cl_get_writeto(t_cl*, int);
char	*cl_get_readfrom(t_cl*, int);
int	get_redir_len(char*);
char	*epur_command_line(char*);

int	env_put_in_list(t_env**, char*, char*);
t_env	*env_rm_from_list(t_env*, char*);
char	*env_get_value_from_list(t_env*, char*);
void	env_change_value_in_list(t_env*, char*, char*);
void	env_show_list(t_env*, char);
int	env_list_size(t_env*);
t_env	*env_to_list(char**);
char	**env_list_to_tab(t_env*);
void	env_list_free(t_env*);
void	free_one_list_elem(t_env*);
int	env_var_exists(t_env*, char*);

int	get_nb_of_path(char*);
char	**path_to_tab(t_env*);

int	count_pipes(t_clm*);
void	my_execve(t_sh*);
void	get_input_fds(int*, int*, t_cl*, t_pid*);
void	get_output_fds(int*, int*, t_cl*, t_pid*);
void	get_double_left(t_cl*, int, int);
void	print_wait_status(t_sh*, int);
int	proceed_father(t_sh*, int*, t_cl**, t_pid*);

int	is_builtin(t_sh*, t_cl*);
int	handle_builtin(t_sh*, t_cl*);
int	handle_cd(t_sh*, t_cl*);
void	handle_setenv(t_sh*, t_cl*);
void	handle_unsetenv(t_sh*, t_cl*);
void	handle_env(t_sh*, t_cl*);
int	handle_exit(t_sh*, t_cl*);
int	handle_alias(t_sh*, t_cl*);
int	handle_unalias(t_sh*, t_cl*);
int	handle_unset(t_sh*, t_cl*);
int	handle_echo(t_sh*, t_cl*);
int	handle_specific_options(t_sh*, t_cl*, int);
int	handle_simplecase(t_sh*, t_cl*);
void	putspecstr(char*);
void	show_specchar(char);

int	ali_handle(t_sh*, t_clm*);
char	*ali_get_value(t_ali*, char*);
int	ali_exists(t_ali*, char*);
int	ali_remove(t_ali**, char*);
int	ali_put_in_list(t_ali**, char*, char*);
void	ali_free_everything(t_ali**);

int	var_handle(t_sh*, t_clm*);
int	var_exists(t_var*, char*);
char	*var_get_value(t_var*, char*);
int	var_put_in_list(t_var**, char*, char*);
int	is_variable(t_sh*, t_cl*);
int	var_create_handle(t_sh*, t_cl*);
int	var_remove(t_var**, char*);
void	var_free_everything(t_var**);

void	my_error(char*);
int	my_perror(char*);
void	write_error(char*);
void	formated_error(char*, char*);

char	*my_concat3(char*, char*, char*);
void	free_wordtab(char**);
int	wordtab_size(char**);
char	**insert_wordtab_after_elem(char**, char**, int);
char	**wtab_remove_one_line(char**, int);
char	**my_explode_quotes(char*);

char	*my_terminal(void);
char	*search_key(char*, int);
char	*my_execution_key(char[10],t_coor*, int*, char*);
int	my_initialization(t_coor*, int);
char	*my_key_delete(t_coor*, int*, char*);
char	*remove_caracter(t_coor*, int*, char*);
void	my_key_left(t_coor*, int*);
void	my_key_right(t_coor*, int*);
char	*my_add_character(t_coor*, int*, char*, char[10]);
void	my_tputs(char*, int, int);
int	where_is_my_position(t_coor*, char*);
void	my_check_size_term(t_coor*);
int	get_value_y();
int	get_value_x();
int	my_reset();
void	my_clean();
int	window_row(struct termios);
int	my_putc(int);

#endif /* !MYSH_H_ */
