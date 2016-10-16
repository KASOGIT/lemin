/*
** load_lemin.c for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Fri Apr 17 11:54:04 2015 Benjamin Rascol
** Last update Fri May  1 16:33:12 2015 Benjamin Rascol
*/

#include "lemin.h"

static int	get_nbr_ant(t_data *anthill, char *str, int cur_line)
{
  printf("%s\n", str);
  if (my_str_isnum(str) == 0 || (anthill->nbr_ant = atoi(str)) <= 0)
    return (error_manager(INVALID_NB_ANT, str, cur_line));
  return (SUCCESS);
}

static int	get_type(t_data *anthill, char *str, int cur_line)
{
  if (my_strcmp(str + 2, "start") == 0)
    {
      if (anthill->room_start->room == NULL)
	return (ROOM_START);
      else
	return (error_manager(MULTIPLE_DEFINE_START_END,
			      str, cur_line));
    }
  if (my_strcmp(str + 2, "end") == 0)
    {
      if (anthill->room_end->room == NULL)
	return (ROOM_END);
      else
	return (error_manager(MULTIPLE_DEFINE_START_END,
			      str, cur_line));
    }
  return (error_manager(INVALID_INSTRUCTION, str, cur_line));
}

static int	load_line(t_data *anthill, char *str, int cur_line)
{
  static t_type	type_room = 0;
  int		i;

  i = count_word(str, ' ', '\t');
  if (*str == '#')
    {
      if (*(str + 1) == '#')
	if ((type_room = get_type(anthill, str, cur_line)) == WARNING_LEMIN)
	  return (WARNING_LEMIN);
    }
  else if (i == 1)
    {
      if (type_room)
      	return (error_manager(PIPE_SPECIFICATION, str, cur_line));
      return (load_pipe(anthill, str, cur_line));
    }
  else if (i == 3)
    return (load_room(anthill, str, &type_room, cur_line));
  else
    return (error_manager(UNKNOW_PARAM, str, cur_line));
  return (SUCCESS);
}

int	load_lemin(t_data *anthill)
{
  char	*str;
  int	ret;
  int	cur_line;

  cur_line = 0;
  ret = 0;
  if ((str = get_next_line(0)) == NULL)
    return (error_manager(NO_DATA, str, cur_line));
  if (get_nbr_ant(anthill, str, cur_line) == ERROR_LEMIN)
    return (ERROR_LEMIN);
  while (cur_line != -1 && (str = get_next_line(0)) != NULL)
    {
      cur_line++;
      if ((ret = load_line(anthill, str, cur_line)) == ERROR_LEMIN)
	return (ERROR_LEMIN);
      else if (ret == WARNING_LEMIN)
	cur_line = -1;
      else
	printf("%s\n", str);
      free(str);
    }
  if (anthill->room_start->room == NULL
      || anthill->room_end->room == NULL)
    return (error_manager(UNDEFINED_START_END, NULL, cur_line));
  return (SUCCESS);
}
