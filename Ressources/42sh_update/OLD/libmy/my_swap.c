/*
** my_swap.c for my_swap in /home/buchse_a/Documents/Piscine-C-Jour_04
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Oct  3 08:52:36 2013 Antoine Buchser
** Last update Thu Apr 24 20:52:14 2014 Antoine Buchser
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}
