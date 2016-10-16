/*
** get_next_line.h for get_next_line in /home/soto_a/rendu/CPE_2014_get_next_line
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Nov 14 12:29:34 2014 Kaso Soto
** Last update Fri Apr 17 11:29:43 2015 Benjamin Rascol
*/

#ifndef GET_NEXT_LINE_H_

# include <stdlib.h>
# include <unistd.h>
# define GET_NEXT_LINE_H_

# define BUFF_SIZE 4096

char	*my_realloc(char *, int);
void	my_reset_buff(char *buffer);
char	*get_line(char *, int, const int);
char	*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
