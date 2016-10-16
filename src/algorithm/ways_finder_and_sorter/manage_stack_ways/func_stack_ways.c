/*
** my_init_stack.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm/manage_stack_ways
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Apr 18 16:08:47 2015 KASO soto
** Last update Sat May  2 01:33:42 2015 adam soto
*/

#include "lemin.h"

/*
** init the root of stack_ways
*/

void	init_stack(t_stack_ways **map)
{
  if (((*map) = malloc(sizeof(t_stack_ways))) == NULL)
    {
      my_putstr("Error when init root stack\n");
      exit(EXIT_FAILURE);
    }
  (*map)->prev = *map;
  (*map)->next = *map;
  (*map)->size_way = 0;
}

/*
** put a new way of room in the stack of ways
*/

void		put_new_way_in_stack(t_stack_ways **map, t_way **way,
				     unsigned int size_way)
{
  t_stack_ways	*new_way;

  if ((new_way = malloc(sizeof(t_stack_ways))) == NULL)
    {
      my_putstr("Error when create a new_way in stack\n");
      exit(EXIT_FAILURE);
    }
  new_way->size_way = size_way;
  new_way->way = *way;
  new_way->prev = (*map)->prev;
  new_way->next = *map;
  (*map)->prev->next = new_way;
  (*map)->prev = new_way;
}

/*
** Free all the memory used by the stack of ways
*/

void	delete_stack(t_stack_ways **map)
{
  t_stack_ways	*tmp;
  t_stack_ways	*to_del;

  tmp = (*map)->next;
  while (tmp != *map)
    {
      to_del = tmp;
      tmp = tmp->next;
      delete_way(&(to_del->way));
    }
  free(*map);
}

/*
** delete a way in the map
*/

void		delete_way_stack(t_stack_ways **elem)
{
  t_stack_ways	*to_del;

  to_del = *elem;
  (*elem)->prev->next = (*elem)->next;
  (*elem)->next->prev = (*elem)->prev;
  free(to_del);
}
