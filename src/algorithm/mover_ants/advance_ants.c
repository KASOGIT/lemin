/*
** advance_ants.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm/mover_ants
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  1 22:22:27 2015 adam soto
** Last update Sat May  2 02:09:45 2015 adam soto
*/

#include "lemin.h"

/*
** display the ant movement
*/

static void	display_ant_movement(unsigned int num_ant, char *name_room)
{
  printf("P%u-%s ", num_ant, name_room);
}

/*
** attribute num for each ant and each room
*/

static void	attribute_num_ant_room(t_way **tmp_way, unsigned int *num_ant)
{
  if ((*tmp_way)->prev->node->room->info_room.type_room == ROOM_START)
    {
      (*num_ant)++;
      (*tmp_way)->node->room->info_room.num_ant = *num_ant;
    }
  else
    (*tmp_way)->node->room->info_room.num_ant =
      (*tmp_way)->prev->node->room->info_room.num_ant;
}

/*
** according to the type of room move a ant
*/

static void		ant_move(t_way **tmp_way)
{
  static unsigned int	num_ant = 0;

  if ((*tmp_way)->node->room->info_room.type_room == ROOM_END
      && (*tmp_way)->prev->node->room->info_room.nbr_ant >= 1)
    {
      attribute_num_ant_room(tmp_way, &num_ant);
      display_ant_movement((*tmp_way)->node->room->info_room.num_ant,
			   (*tmp_way)->node->room->info_room.name_room);
      (*tmp_way)->node->room->info_room.nbr_ant++;
      (*tmp_way)->prev->node->room->info_room.nbr_ant--;
    }
  else if ((*tmp_way)->node->room->info_room.type_room == ROOM_DEFAULT
	   && (*tmp_way)->prev->node->room->info_room.nbr_ant > 0
	   && (*tmp_way)->node->room->info_room.nbr_ant == 0)
    {
      attribute_num_ant_room(tmp_way, &num_ant);
      display_ant_movement((*tmp_way)->node->room->info_room.num_ant,
			   (*tmp_way)->node->room->info_room.name_room);
      (*tmp_way)->node->room->info_room.nbr_ant = 1;
      (*tmp_way)->prev->node->room->info_room.nbr_ant--;
    }
}

/*
** advance ants on best found ways
*/

void		advance_ants(t_data *data, t_stack_ways **map)
{
  t_stack_ways	*tmp_map;
  t_way		*tmp_way;

  while (data->room_end->room->info_room.nbr_ant != data->nbr_ant)
    {
      tmp_map = (*map)->next;
      while (tmp_map != *map)
        {
          tmp_way = tmp_map->way->prev;
          while (tmp_way->prev && tmp_way->prev != tmp_map->way)
            {
	      ant_move(&tmp_way);
              tmp_way = tmp_way->prev;
            }
          tmp_map = tmp_map->next;
        }
      printf("\n");
    }
}
