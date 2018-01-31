/*
** my_strcmp.c for my_strcmp in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Oct  7 09:59:47 2013 Antoine Buchser
** Last update Tue May  6 15:26:12 2014 Antoine Buchser
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	check;

  i = 0;
  check = 1;
  while (s1[i] && s2[i] && check == 1 && i != n)
    {
      if (s1[i] != s2[i])
	check = 0;
      i++;
    }
  if (check == 1)
    return (0);
  else
    return (s1[i - 1] - s2[i - 1]);
}
