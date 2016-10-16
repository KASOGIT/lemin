/*
** algorithm.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Apr 18 16:36:11 2015 KASO soto
** Last update Fri May  1 22:32:16 2015 adam soto
*/

#include "lemin.h"

static void	aff_found_ways(t_stack_ways *map)
{
  int		i;
  t_stack_ways	*tmp_m;
  t_way		*tmp_w;

  i = 1;
  tmp_m = map->next;
  while (tmp_m != map)
    {
      printf("way : %d of size : %d\n", i, tmp_m->size_way);
      tmp_w = tmp_m->way->next;
      while (tmp_w != tmp_m->way)
	{
	  printf("room : %s\n", tmp_w->node->room->info_room.name_room);
	  tmp_w = tmp_w->next;
	}
      tmp_m = tmp_m->next;
      i++;
    }
}

/*
** run the search of best ways and run the ants in
*/

void		algorithm(t_data *data)
{
  t_stack_ways	*map;
  t_way		*way;

  init_stack(&map);
  init_way(&way);
  search_best_ways_in_stack(&(data->room_start), &map, &way);
  delete_way(&way);
  if (map != map->next)
    {
      sort_ways(&map);
      aff_found_ways(map);
      advance_ants(data, &map);
    }
  else
    fprintf(stderr, "No way found to end room.\n");
}
