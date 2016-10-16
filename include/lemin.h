/*
** lemin.h for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Tue Apr 14 17:45:16 2015 Benjamin Rascol
** Last update Sun May  3 20:03:33 2015 oliva clement
*/

#ifndef				LEMIN_H_
# define			LEMIN_H_

# include			<stdlib.h>
# include			<stdio.h>
# include			"my.h"
# include			"linked_list.h"

# define	SUCCESS		0

# define	ROOM_DEFAULT	0
# define	ROOM_START	2
# define	ROOM_END	3

/*
** Error management structure.
*/

typedef struct	s_error
{
  char		error_ret;
  char		error_sig;
  char		*error_msg;
}		t_error;

/*
** stack for save ways and contain all possible ways
** extract from graph
*/

typedef struct	s_way
{
  struct s_way	*prev;
  struct s_way	*next;
  int		size_way;
  t_list	*node;
}		t_way;

typedef struct		s_stack_ways
{
  struct s_stack_ways	*prev;
  struct s_stack_ways	*next;
  t_way			*way;
  unsigned int		size_way;
}			t_stack_ways;

# define	WARNING_IGNORE			2
# define	WARNING_LEMIN			1
# define	ERROR_LEMIN			-1
# define	INVALID_NB_ANT			-2
# define	INVALID_INSTRUCTION		-3
# define	INVALID_POSITION		-4
# define	MALLOC_FAILED			-5
# define	INVALID_PIPE			-6
# define	PIPE_SPECIFICATION		-7
# define	UNKNOW_PARAM			-8
# define	NO_DATA				-9
# define	UNINITIALISED_ROOT		-10
# define	UNKNOW_ROOM_NAME		-11
# define	UNDEFINED_START_END		-12
# define	MULTIPLE_DEFINE_START_END	-13
# define	MULTIPLE_PIPE_DEFINITION	-14

int		error_manager(char cur_sig, char *str, int cur_line);
int		load_room(t_data *anthill, char *str,
			  t_type *type_room, int cur_line);
int		load_pipe(t_data *anthill, char *str, int cur_line);
int		load_lemin(t_data *anthill);
void		init_way(t_way **way);
void		put_room_in_way(t_way **way, t_list **node);
int		size_way(t_way *way);
void		delete_way(t_way **way);
void		init_stack(t_stack_ways **map);
void		put_new_way_in_stack(t_stack_ways **map, t_way **way,
				     unsigned int size_way);
void		delete_stack(t_stack_ways **map);
void		delete_way_stack(t_stack_ways **elem);
void		algorithm(t_data *data);
int		search_best_ways_in_stack(t_list **node, t_stack_ways **map,
					  t_way **cop_way);
void		advance_ants(t_data *data, t_stack_ways **map);
void		copy_way(t_way **way, t_way **new_way);
void		del_way_in_map_by_pos(t_stack_ways **map, int num_way);
void		sort_ways(t_stack_ways **map);
int		uncheck_state_worst_way(t_way **way1, t_way **way2, int num_way);
int		is_same_way_than_another(t_stack_ways **map, t_way **way);
int		is_best_way(t_stack_ways **map, t_way **way);
int		is_worst_than_other_way(t_stack_ways **map, t_way **way);
int		is_not_in_way(t_way **way, t_list **node, t_list **actual_node);
int		is_end_of_way(t_list **node, t_way **way);
int		is_name_match(char *name1, char *name2);

#endif			/* !LEMIN_H_ */
