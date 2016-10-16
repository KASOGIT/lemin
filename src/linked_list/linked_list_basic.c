/*
** basic.c for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Thu Apr 16 17:04:04 2015 Benjamin Rascol
** Last update Wed Apr 22 17:45:32 2015 Benjamin Rascol
*/

#include "lemin.h"

/*
** Create and init node.
*/

static t_list	*create_node(t_room *room)
{
  t_list	*new;

  new = malloc(sizeof(t_list));
  if (new == NULL)
    {
      my_putstr("Error : malloc failed.");
      return (NULL);
    }
  new->room = room;
  new->prev = new;
  new->next = new;
  return (new);
}

/*
** Add node to the double linked list.
*/

int		linked_list_add_node(t_list **head, t_room *room)
{
  t_list	*new;

  new = create_node(room);
  if (*head == NULL)
    return (error_manager(UNINITIALISED_ROOT, NULL, 0));
  else
    {
      new->next = *head;
      new->prev = (*head)->prev;
      (*head)->prev->next = new;
      (*head)->prev = new;
    }
  return (SUCCESS);
}

/*
** Init root
*/

int		linked_list_init_root(t_list **root)
{
  *root = malloc(sizeof(t_list));
  if (*root == NULL)
    {
      my_putstr("Error : malloc failed.");
      return (error_manager(MALLOC_FAILED, NULL, 0));
    }
  (*root)->room = NULL;
  (*root)->prev = *root;
  (*root)->next = *root;
  return (SUCCESS);
}

/*
** Assign a t_list ptr to a linked list.
*/

int		linked_list_add_ptr(t_list **head, t_list **node)
{
  if (*head == NULL)
    return (error_manager(UNINITIALISED_ROOT, NULL, 0));
  else
    {
      (*node)->next = *head;
      (*node)->prev = (*head)->prev;
      (*head)->prev->next = *node;
      (*head)->prev = *node;
    }
  return (SUCCESS);
}
