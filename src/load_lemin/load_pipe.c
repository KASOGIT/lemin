/*
** load_pipe.c for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Thu Apr 23 10:59:59 2015 Benjamin Rascol
** Last update Wed Apr 29 11:38:37 2015 Benjamin Rascol
*/

#include "lemin.h"

static int	is_already_defined(t_list *save_tab0, t_list *save_tab1,
				   char *str, int cur_line)
{
  t_list	*tmp;

  tmp = save_tab0->room->connected_rooms;
  tmp = tmp->next;
  while (tmp != save_tab0->room->connected_rooms)
    {
      if (my_strcmp(tmp->room->info_room.name_room,
		    save_tab1->room->info_room.name_room) == 0)
	return (error_manager(MULTIPLE_PIPE_DEFINITION, str, cur_line));
      tmp = tmp->next;
    }
  return (SUCCESS);
}

static int	get_connected_rooms(t_data *anthill, char **tab,
				    t_list **save_tab0, t_list **save_tab1)
{
  t_list	*tmp;

  tmp = anthill->room_list;
  tmp = tmp->next;
  while (tmp != anthill->room_list)
    {
      if (my_strcmp(tab[0], tmp->room->info_room.name_room) == 0)
	*save_tab0 = tmp;
      else if (my_strcmp(tab[1], tmp->room->info_room.name_room) == 0)
	*save_tab1 = tmp;
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int		load_pipe(t_data *anthill, char *str, int cur_line)
{
  char		**tab;
  t_list	*save_tab0;
  t_list	*save_tab1;

  tab = my_str_to_wordtab(str, '-', '\0');
  if (count_wordtab(tab) != 2
      || my_strcmp(tab[0], tab[1]) == 0)
    return (error_manager(INVALID_PIPE, str, cur_line));
  save_tab0 = NULL;
  save_tab1 = NULL;
  get_connected_rooms(anthill, tab, &save_tab0, &save_tab1);
  free_wordtab(tab);
  if (save_tab0 == NULL || save_tab1 == NULL)
    return (error_manager(UNKNOW_ROOM_NAME, str, cur_line));
  if (is_already_defined(save_tab0, save_tab1, str, cur_line) == WARNING_LEMIN)
    return (WARNING_LEMIN);
  linked_list_add_node(&(save_tab0->room->connected_rooms), save_tab1->room);
  linked_list_add_node(&(save_tab1->room->connected_rooms), save_tab0->room);
  return (SUCCESS);
}
