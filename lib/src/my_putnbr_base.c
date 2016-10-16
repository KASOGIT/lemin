/*
** my_putnbr_base.c for my_putnbr_base.c in /home/soto_a/rendu/Piscine_C_J06
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Oct  7 09:51:33 2014 adam kaso
** Last update Sun May  3 18:48:15 2015 adam soto
*/

#include "my.h"

static void	util(int size_base, int *nbr)
{
  if (*nbr < 0)
    {
      my_putchar('-');
      *nbr = -(*nbr);
    }
}

int	my_putnbr_base(int nbr, char *base, int step)
{
  int	count;
  int	result;
  int	div;
  int	size_base;

  count = 0;
  div = 1;
  util(size_base = my_strlen(base), &nbr);
  while (nbr / div >= size_base)
    div *= size_base;
  while (div > 0)
    {
      count++;
      result = (nbr / div) % size_base;
      my_putchar(base[result]);
      if (step + count == 32)
	{
	  my_putchar('\n');
	  step = 0;
	  count = 0;
	}
      div /= size_base;
    }
  return (count);
}
