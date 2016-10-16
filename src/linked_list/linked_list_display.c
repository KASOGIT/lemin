/*
** linked_list_display.c for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin/src/linked_list
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Thu Apr 16 18:16:19 2015 Benjamin Rascol
** Last update Mon Apr 20 19:34:55 2015 Benjamin Rascol
*/

#include "lemin.h"

inline void	linked_list_display_node(t_list *node)
{
  if (node->room != NULL)
    {
      printf("\t\t\tRoom Name : %s\n", node->room->info_room.name_room);
      if (node->room->info_room.type_room == 0)
	printf("\t\t\tType : NORMAL\n");
      else if (node->room->info_room.type_room == 1)
	printf("\t\t\tType : STARTING ROOM\n");
      else if (node->room->info_room.type_room == 2)
	printf("\t\t\tType : ENDING ROOM\n");
      printf("\t\t\tNb ant : %d\n", node->room->info_room.nbr_ant);
      printf("\t\t\tPosition :\n\t\t\t\tx : %d\n\t\t\t\ty : %d\n",
	     node->room->info_room.pos.x, node->room->info_room.pos.y);
    }
  else
    printf("room == NULL\n");
}

static void	linked_list_display_connected_list(t_list *list)
{
  t_list	*tmp;

  if (list == NULL)
    {
      printf("Error : try to display a NULL list\n");
      return ;
    }
  if (list->next == list)
    {
      printf("\t\t\tEmpty list.\n");
    }
  tmp = list->next;
  while (tmp != list)
    {
      linked_list_display_node(tmp);
      tmp = tmp->next;
    }
}

void		linked_list_display_list(t_list *list)
{
  t_list	*tmp;

  if (list == NULL)
    {
      printf("Error : try to display a NULL list\n");
      return ;
    }
  tmp = list->next;
  while (tmp != list)
    {
      printf("\n---------\n");
      printf("\t\t\e[104mNew Node :\e[0m\n");
      linked_list_display_node(tmp);
      printf("\t\t\e[101mConnected rooms\e[0m\n");
      linked_list_display_connected_list(tmp->room->connected_rooms);
      printf("\t\t\e[101mEND OF Connected rooms\e[0m\n");
      printf("\t\t\e[104mEND OF NODE\e[0m\n");
      tmp = tmp->next;
    }
}
