/*
** linked_list_removal.c for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin/src/linked_list
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Thu Apr 16 17:49:41 2015 Benjamin Rascol
** Last update Thu Apr 23 13:35:20 2015 Benjamin Rascol
*/

#include "lemin.h"

void		linked_list_delete_node(t_list **node)
{
  t_list	*tmp;

  if (*node == NULL)
    return ;
  (*node)->next->prev = (*node)->prev;
  (*node)->prev->next = (*node)->next;
  tmp = *node;
  *node = (*node)->next;
  free((*node)->room->info_room.name_room);
  free(tmp->room);
  free(tmp);
}

void		linked_list_delete_list(t_list **list)
{
  while (*list != NULL)
    {
      linked_list_delete_node(list);
    }
}
