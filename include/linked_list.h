/*
** linkedlist.h for linked_list.h in /home/soto_a/rendu/PSU_2014_minishell1/myshll
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Jan 20 19:10:23 2015 Kaso Soto
** Last update Fri May  1 23:22:53 2015 adam soto
*/

#ifndef		LINKED_LIST_H_
# define	LINKED_LIST_H_

typedef		char	t_type;
typedef		short	t_bool;

typedef struct	s_room	t_room;

typedef struct	s_list
{
  t_room	*room;
  struct s_list	*prev;
  struct s_list	*next;
}		t_list;

typedef struct	s_pos
{
  unsigned int	x;
  unsigned int	y;
}		t_pos;

typedef struct	s_info_room
{
  char		*name_room;
  t_type	type_room;
  t_bool	visited;
  unsigned int	nbr_ant;
  unsigned int	num_ant;
  t_pos		pos;
}		t_info_room;

struct	s_room
{
  t_list	*connected_rooms;
  t_info_room	info_room;
};

typedef struct	s_data
{
  t_list	*room_list;
  t_list	*room_start;
  t_list	*room_end;
  unsigned int	nbr_ant;
}		t_data;

/*
** File : linked_list_basic.c
**
** Description : create node to stock room and add it in list.
*/

int		linked_list_add_node(t_list **head, t_room *room);
void		linked_list_delete_node(t_list **node);
void		linked_list_delete_list(t_list **list);
void		linked_list_display_node(t_list *node);
void		linked_list_display_list(t_list *list);
int		linked_list_init_root(t_list **root);

#endif /* !LINKED_LIST_H_ */
