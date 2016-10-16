/*
** copy_way.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm/manage_act
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  1 22:06:41 2015 adam soto
** Last update Fri May  1 22:07:47 2015 adam soto
*/

#include "lemin.h"

/*
** copy a way into a new
*/

void		copy_way(t_way **way, t_way **new_way)
{
  t_way		*tmp;

  tmp = (*way)->next;
  init_way(new_way);
  (*new_way)->size_way = (*way)->size_way;
  while (tmp != *way)
    {
      put_room_in_way(new_way, &(tmp->node));
      tmp = tmp->next;
    }
}
