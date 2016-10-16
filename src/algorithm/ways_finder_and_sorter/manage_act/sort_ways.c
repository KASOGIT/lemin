/*
** sort_ways.c for  in /home/soto_a/rendu/CPE_2014_lemin/src/algorithm/manage_act
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  1 22:12:41 2015 adam soto
** Last update Fri May  1 22:14:24 2015 adam soto
*/

#include "lemin.h"

/*
** sort the ways by their size in ascneding order
*/

void		sort_ways(t_stack_ways **map)
{
  int		tmp_size;
  t_stack_ways	*tmp;
  t_way		*tmp_w;

  tmp = (*map)->next;
  while (tmp->next != *map)
    {
      if (tmp->size_way > tmp->next->size_way)
        {
          tmp_size = tmp->size_way;
          tmp->size_way = tmp->next->size_way;
          tmp->next->size_way = tmp_size;
          copy_way(&(tmp->way), &tmp_w);
          delete_way(&(tmp->way));
          copy_way(&(tmp->next->way), &(tmp->way));
          delete_way(&(tmp->next->way));
          copy_way(&(tmp_w), &(tmp->next->way));
          delete_way(&tmp_w);
          tmp = (*map)->next;
        }
      else
        tmp = tmp->next;
    }
}
