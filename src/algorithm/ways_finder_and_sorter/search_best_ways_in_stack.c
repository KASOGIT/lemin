/*
** search_best_ways_in_stack.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  1 22:17:22 2015 adam soto
** Last update Sat May  2 12:32:40 2015 adam soto
*/

#include "lemin.h"

/*
** if the way reaches the end, made all the test and return
*/

static int	way_reaches_end(t_stack_ways **map, t_way **cop_way)
{
  t_way		*new_way;
  int		num_way;

  if (is_same_way_than_another(map, cop_way) == 0
      && (num_way = is_best_way(map, cop_way)) != 0)
    {
      if (num_way != -1)
	del_way_in_map_by_pos(map, num_way);
      copy_way(cop_way, &new_way);
      put_new_way_in_stack(map, &new_way, (*cop_way)->size_way);
    }
  delete_way(cop_way);
  return (0);
}

/*
** way can't continue, banish the node
*/

static int	way_cant_continue(t_way **cop_way, t_list **node,
				  t_bool end_of_way)
{
  delete_way(cop_way);
  if (end_of_way)
    (*node)->room->info_room.visited = 1;
  return (0);
}

/*
** search all available ways in graph
*/

int		search_best_ways_in_stack(t_list **node, t_stack_ways **map,
					  t_way **cop_way)
{
  t_list	*tmp_connected;
  t_way		*new_way;
  t_bool	end_of_way;

  put_room_in_way(cop_way, node);
  (*cop_way)->size_way++;
  if ((*node)->room->info_room.type_room == ROOM_END)
    return (way_reaches_end(map, cop_way));
  else if ((end_of_way = is_end_of_way(node, cop_way))
	   || is_worst_than_other_way(map, cop_way))
    return (way_cant_continue(cop_way, node, end_of_way));
  (*node)->room->info_room.visited = 1;
  tmp_connected = (*node)->room->connected_rooms->next;
  while (tmp_connected != (*node)->room->connected_rooms)
    {
      if (is_not_in_way(cop_way, &tmp_connected, node)
          && tmp_connected->room->info_room.visited == 0
          && tmp_connected->room->info_room.type_room != ROOM_START)
        {
          copy_way(cop_way, &new_way);
          search_best_ways_in_stack(&tmp_connected, map, &new_way);
        }
      tmp_connected = tmp_connected->next;
    }
  return (0);
}
