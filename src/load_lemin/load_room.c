/*
** load_room.c for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed Apr 22 18:31:31 2015 Benjamin Rascol
** Last update Thu Apr 23 14:59:08 2015 Benjamin Rascol
*/

#include "lemin.h"

static int	init_room(t_data *anthill, t_room **room,
			   t_type *type_room, char **tab)
{
  *room = malloc(sizeof(t_room));
  if (*room == NULL)
    return (error_manager(MALLOC_FAILED, NULL, 0));
  linked_list_init_root(&((*room)->connected_rooms));
  (*room)->info_room.name_room = my_strdup(tab[0]);
  (*room)->info_room.visited = 0;
  (*room)->info_room.pos.x = (unsigned int)atoi(tab[1]);
  (*room)->info_room.pos.y = (unsigned int)atoi(tab[2]);
  if (((*room)->info_room.type_room = *type_room) == ROOM_START)
    (*room)->info_room.nbr_ant = anthill->nbr_ant;
  else
    (*room)->info_room.nbr_ant = 0;
  if (*type_room == ROOM_START)
    anthill->room_start->room = *room;
  else if (*type_room == ROOM_END)
    anthill->room_end->room = *room;
  linked_list_add_node(&(anthill->room_list), *room);
  *type_room = 0;
  free_wordtab(tab);
  return (SUCCESS);
}

int		load_room(t_data *anthill, char *str,
			  t_type *type_room, int cur_line)
{
  char		**tab;
  t_room	*room;

  tab = my_str_to_wordtab(str, ' ', '\t');
  if (my_str_isnum(tab[1]) == 0 || my_str_isnum(tab[2]) == 0)
    {
      free_wordtab(tab);
      return (error_manager(INVALID_POSITION, str, cur_line));
    }
  return (init_room(anthill, &room, type_room, tab));
}
