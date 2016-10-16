/*
** func_ways.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm/manage_stack_ways
** 
** Made by KASO soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Apr 18 16:22:29 2015 KASO soto
** Last update Mon Apr 27 19:10:08 2015 KASO soto
*/

#include "lemin.h"

/*
** init the root of a way list
*/

void	init_way(t_way **way)
{
  if (((*way) = malloc(sizeof(t_way))) == NULL)
    {
      my_putstr("Error when create root for way\n");
      exit(EXIT_FAILURE);
    }
  (*way)->size_way = 0;
  (*way)->next = *way;
  (*way)->prev = *way;
}

/*
** Put a new room in the way list
*/

void	put_room_in_way(t_way **way, t_list **node)
{
  t_way	*new_room;

  if ((new_room = malloc(sizeof(t_way))) == NULL)
    {
      my_putstr("Error when create a new way\n");
      exit(EXIT_FAILURE);
    }
  new_room->node = *node;
  new_room->next = *way;
  new_room->prev = (*way)->prev;
  (*way)->prev->next = new_room;
  (*way)->prev = new_room;
}

/*
** Free all the memory used by a way list
*/

void	delete_way(t_way **way)
{
  t_way	*tmp;
  t_way	*to_del;

  tmp = (*way)->next;
  while (tmp != *way)
    {
      to_del = tmp;
      tmp = tmp->next;
      free(to_del);
    }
  free(*way);
}

/*
** count nbr of room in a way
*/

int	size_way(t_way *way)
{
  int	count;
  t_way	*tmp;

  count = 0;
  tmp = way->next;
  while (tmp != way)
    {
      count++;
      tmp = tmp->next;
    }
  return (count);
}
