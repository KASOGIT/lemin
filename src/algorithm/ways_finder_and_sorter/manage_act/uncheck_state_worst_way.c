/*
** uncheck_state_worst_way.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm/manage_act
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  1 22:08:22 2015 adam soto
** Last update Sat May  2 02:17:28 2015 adam soto
*/

#include "lemin.h"

/*
** assign worst and best way
*/

static int	assign_best_worst_way(t_way **way1, t_way **way2,
				      t_way **best, t_way **worst)
{
  if ((*way1)->size_way < (*way2)->size_way)
    {
      *best = *way1;
      *worst = *way2;
      return (0);
    }
  else
    {
      *best = *way2;
      *worst = *way1;
      return (1);
    }
}

/*
** check if node match
*/

static void	is_node_match(t_way **tmp_worst, t_way **tmp_best,
			      t_bool *check)
{
  if (is_name_match((*tmp_worst)->node->room->info_room.name_room,
		    (*tmp_best)->node->room->info_room.name_room)
      && (*tmp_worst)->node->room->info_room.type_room != ROOM_START
      && (*tmp_worst)->node->room->info_room.type_room != ROOM_END)
    *check = 1;
}

/*
** uncheck the visited statements on the worst way
*/

int		uncheck_state_worst_way(t_way **way1, t_way **way2, int num_way)
{
  t_bool	check;
  int		type;
  t_way		*best;
  t_way		*worst;
  t_way		*tmp_best;
  t_way		*tmp_worst;

  type = assign_best_worst_way(way1, way2, &best, &worst);
  tmp_worst = worst->next;
  while (tmp_worst != worst)
    {
      tmp_best = best->next;
      check = 0;
      while (tmp_best != best)
        {
	  is_node_match(&tmp_worst, &tmp_best, &check);
          tmp_best = tmp_best->next;
        }
      if (check == 0)
        tmp_worst->node->room->info_room.visited = 0;
      tmp_worst = tmp_worst->next;
    }
  return ((type == 1) ? num_way : 0);
}
