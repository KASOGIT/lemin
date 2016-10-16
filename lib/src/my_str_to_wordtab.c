/*
** my_str_to_wordtab_sep.c for my_str_to_wordtab_sep in /home/ben/rendu/PSU/PSU_2014_minishell1
** 
** Made by Benjamin Rascol
** Login   <ben@epitech.net>
** 
** Started on  Mon Jan 26 16:51:50 2015 Benjamin Rascol
** Last update Sun May  3 18:40:46 2015 adam soto
*/

#include "my_str_to_wordtab.h"

char	**my_str_to_wordtab(char *str, char sep1, char sep2)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  if ((i = count_word(str, sep1, sep2)) == 0
      || (tab = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  while (str[i] != '\0')
    {
      while ((str[i] == sep1 || str[i] == sep2) && str[i] != '\0')
	i++;
      tab[k] = malloc_str(str, i, sep1, sep2);
      j = 0;
      while (str[i] != sep1 && str[i] != sep2 && str[i] != '\0')
	{
	  tab[k][j] = str[i++];
	  j++;
	}
      k++;
    }
  tab[k] = NULL;
  return (tab);
}

char	*malloc_str(char *str, int i, char sep1, char sep2)
{
  char	*result;
  int	j;

  j = 0;
  while (str[i] != sep1 && str[i] != sep2 && str[i] != '\0')
    {
      i++;
      j++;
    }
  if (j > 0)
    {
      result = malloc(sizeof(char) * (j + 1));
      result[j] = '\0';
      return (result);
    }
  return (NULL);
}

int	count_word(char *str, char sep1, char sep2)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (str[i] != '\0')
    {
      if (str[i] != sep1 && str[i] != sep2)
	{
	  while (str[i] != '\0' && str[i] != sep1 && str[i] != sep2)
	    i++;
	  k++;
	}
      if (str[i] != '\0')
	i++;
    }
  return (k);
}

int	free_wordtab(char **tab)
{
  int	i;

  if (tab == NULL)
    return (0);
  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
  return (0);
}

int	count_wordtab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    i++;
  return (i);
}
