/*
** comparing_a_way_relative_map.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm/manage_comparison
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  1 21:56:46 2015 adam soto
** Last update Sat May  2 00:44:39 2015 adam soto
*/

#include "lemin.h"

/*
** check if a way is the same than another in the map
*/

static void	is_node_match(t_way **tmp1, t_way **tmp2, int *count)
{
  if (is_name_match((*tmp1)->node->room->info_room.name_room,
		    (*tmp2)->node->room->info_room.name_room) == 0)
    (*count)++;
}

int		is_same_way_than_another(t_stack_ways **map, t_way **way)
{
  int		count;
  t_stack_ways	*tmp;
  t_way		*tmp_m;
  t_way		*tmp_w;

  tmp = (*map)->next;
  while (tmp != *map)
    {
      count = 0;
      tmp_m = tmp->way->next;
      tmp_w = (*way)->next;
      if (tmp_m->size_way == tmp_w->size_way)
        {
          while (tmp_m != tmp->way && tmp_w != *way && count == 0)
            {
	      is_node_match(&tmp_m, &tmp_w, &count);
              tmp_m = tmp_m->next;
              tmp_w = tmp_w->next;
            }
          if (count == 0)
            return (1);
        }
      tmp = tmp->next;
    }
  return (0);
}

/*
** compare is the new way is better than another ways wich are similar
** and if it's a new way
*/

int		is_best_way(t_stack_ways **map, t_way **way)
{
  t_stack_ways	*tmp_m;
  t_way		*tmp_w;
  t_way		*tmp_actual_w;
  int		num_way;

  num_way = 1;
  tmp_m = (*map)->next;
  while (tmp_m != *map)
    {
      tmp_w = tmp_m->way->next;
      tmp_actual_w = (*way)->next;
      while (tmp_w != tmp_m->way && tmp_actual_w != *way)
        {
          if (is_name_match(tmp_w->node->room->info_room.name_room,
                            tmp_actual_w->node->room->info_room.name_room)
              && tmp_w->node->room->info_room.type_room == ROOM_DEFAULT
              && tmp_actual_w->node->room->info_room.type_room == ROOM_DEFAULT)
            return (uncheck_state_worst_way(&(tmp_m->way), way, num_way));
          tmp_actual_w = tmp_actual_w->next;
          tmp_w = tmp_w->next;
        }
      num_way++;
      tmp_m = tmp_m->next;
    }
  return (-1);
}

/*
** just check if the way is lees good than another
*/

int		is_worst_than_other_way(t_stack_ways **map, t_way **way)
{
  t_stack_ways	*tmp_m;
  t_way		*tmp_w;
  t_way		*tmp_actual_w;

  tmp_m = (*map)->next;
  while (tmp_m != *map)
    {
      tmp_w = tmp_m->way->next;
      tmp_actual_w = (*way)->next;
      while (tmp_w != tmp_m->way && tmp_actual_w != *way)
        {
          if (is_name_match(tmp_w->node->room->info_room.name_room,
                            tmp_actual_w->node->room->info_room.name_room)
              && tmp_w->node->room->info_room.type_room == ROOM_DEFAULT
              && tmp_actual_w->node->room->info_room.type_room == ROOM_DEFAULT
              && tmp_w->size_way <= tmp_actual_w->size_way)
            return (1);
          tmp_actual_w = tmp_actual_w->next;
          tmp_w = tmp_w->next;
        }
      tmp_m = tmp_m->next;
    }
  return (0);
}
