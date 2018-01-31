/*
** mystr.h for mystr in /home/schoch_h/Lib/mystr
** 
** Made by Hugo Schoch
** Login   <schoch_h@epitech.net>
** 
** Started on  Thu May  1 13:35:52 2014 Hugo Schoch
** Last update Fri May  9 23:12:48 2014 Hugo Schoch
*/

#ifndef MY_STR_
# define MY_STR_

char	**my_realloc_tab(char**, int);
char	*my_realloc(char*, int);
char	*my_revstr(char*);
char	*my_str_insert(char*, int, char*);
char	**my_str_to_wordtab_lim(char*, char*);
char	**my_str_to_wordtab(char*);
char	*my_strcat(char*, char*);
char	*my_strncat(char*, char*, int);
int	my_strcmp(char*, char*);
int	my_strncmp(char*, char*, int);
char	*my_strcpy(char*, char*);
char	*my_strncpy(char*, char*, int);
char	*my_strdup(char*);
char	*my_strndup(char*, int);
int	my_tab_strlen(char**);
int	my_strlen(char*);
char	**my_explode(char*);

#endif /* !MY_STR_ */
