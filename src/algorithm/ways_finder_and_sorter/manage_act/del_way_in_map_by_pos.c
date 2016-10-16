/*
** del_way_in_map_by_pos.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm/manage_act
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  1 22:10:30 2015 adam soto
** Last update Fri May  1 22:11:45 2015 adam soto
*/

#include "lemin.h"

/*
** delete a way in the map by its position in a map
*/

void		del_way_in_map_by_pos(t_stack_ways **map, int num_way)
{
  int		i;
  t_stack_ways	*tmp;

  i = 1;
  tmp = (*map)->next;
  while (tmp != *map)
    {
      if (i == num_way)
        {
          delete_way_stack(&tmp);
          return ;
        }
      i++;
      tmp = tmp->next;
    }
}
