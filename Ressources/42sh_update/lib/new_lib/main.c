#include "mini.h"

int	main(void)
{
  my_putstr("salut les gars\n");
  my_putnbr(my_getnbr("+++-+-1509743afzef"));
  my_putchar('\n');
  if (!my_strcmp("salut", "salut"))
    my_putstr("ca match\n");
  if (my_strncmp("salut", "salu", 4))
    my_putstr("ca match\n");
  if (my_strcmp("salut", "salu"))
    my_putstr("ca match pas\n");
  my_putnbr_base(42, "01");
  my_putstr("\n");
  my_putnbr(my_getnbr_base("101010", "01"));
  my_putstr("\n");
  return (0);
}
