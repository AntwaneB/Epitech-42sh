/*
** replace_glob.c for glob in /home/giubil_v
**
** Made by victor giubilei
** Login   <giubil_v@epitech.net>
**
** Started on  Wed May  7 13:02:51 2014 victor giubilei
** Last update Wed May  7 13:03:11 2014 victor giubilei
*/

#include <glob.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
  glob_t	s;
  unsigned long  i = -1;

  if (glob(av[1], 0, NULL, &s))
    printf("ERROR !\n");
  else
    while (++i < s.gl_pathc)
      printf("%s\n", s.gl_pathv[i]);
  return (0);
}



/* #include <stdlib.h> */
/* #include <string.h> */
/* #include <glob.h> */

/* /\* Convert a wildcard pattern into a list of blank-separated */
/*    filenames which match the wildcard.  *\/ */

/* char * glob_pattern(char *wildcard) */
/* { */
/*   char *gfilename; */
/*   size_t cnt, length; */
/*   glob_t glob_results; */
/*   char **p; */

/*   glob(wildcard, GLOB_NOCHECK, 0, &glob_results); */

/*   length = 0; */
/*   /\* How much space do we need?  *\/ */
/*   for (p = glob_results.gl_pathv, cnt = glob_results.gl_pathc; */
/*        cnt; p++, cnt--) */
/*     length += strlen(*p) + 1; */

/*   /\* Allocate the space and generate the list.  *\/ */
/*   gfilename = (char *) calloc(length, sizeof(char)); */
/*   for (p = glob_results.gl_pathv, cnt = glob_results.gl_pathc; */
/*        cnt; p++, cnt--) */
/*     { */
/*       strcat(gfilename, *p); */
/*       if (cnt > 1) */
/*	strcat(gfilename, " "); */
/*     } */

/*   globfree(&glob_results); */
/*   return gfilename; */
/* } */

/* int	main(int ac, char **av) */
/* { */
/*   printf("%s\n", glob_pattern(av[1])); */
/* } */
