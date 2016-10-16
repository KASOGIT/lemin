/*
** comparison_on_way.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm/manage_comparison
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  1 21:39:24 2015 adam soto
** Last update Fri May  1 21:53:32 2015 adam soto
*/

#include "lemin.h"

/*
** check is node is already in a way
*/

int		is_not_in_way(t_way **way, t_list **node, t_list **actual_node)
{
  t_way		*tmp_way;

  tmp_way = (*way)->next;
  while (tmp_way != *way)
    {
      if (is_name_match(tmp_way->node->room->info_room.name_room,
                        (*node)->room->info_room.name_room)
          && is_name_match((*actual_node)->room->info_room.name_room,
                           tmp_way->node->room->info_room.name_room) == 0)
        return (0);
      tmp_way = tmp_way->next;
    }
  return (1);
}

/*
** test if the way can continue
*/

int		is_end_of_way(t_list **node, t_way **way)
{
  t_list	*tmp_connected;

  tmp_connected = (*node)->room->connected_rooms->next;
  while (tmp_connected != (*node)->room->connected_rooms)
    {
      if (is_not_in_way(way, &tmp_connected, node)
          && tmp_connected->room->info_room.visited == 0)
        return (0);
      tmp_connected = tmp_connected->next;
    }
  return (1);
}

/*
** check if two name match
*/

int	is_name_match(char *name1, char *name2)
{
  int	i;

  i = 0;
  while (name1[i] && name2[i])
    {
      if (name1[i] != name2[i])
        return (0);
      i++;
    }
  return (name1[i] == name2[i] ? 1 : 0);
}
