/*
** my_str_to_wordtab.h for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Fri Apr 17 17:16:12 2015 Benjamin Rascol
** Last update Fri Apr 17 17:23:27 2015 Benjamin Rascol
*/

#ifndef MY_STR_TO_WORDTAB_H_
# define MY_STR_TO_WORDTAB_H_

# include "my.h"

int		count_word(char *str, char sep1, char sep2);
int		free_wordtab(char **tab1);
int		count_wordtab(char **tab1);
char		*malloc_str(char *str, int i, char sep1, char sep2);
char		**my_str_to_wordtab(char *str, char sep1, char sep2);

#endif /* !MY_STR_TO_WORDTAB_H_ */
