##
## Makefile for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin
## 
## Made by Benjamin Rascol
## Login   <rascol_b@epitech.net>
## 
## Started on  Tue Apr 14 17:39:35 2015 Benjamin Rascol
## Last update Sun Oct 16 13:46:24 2016 
##

NAME	=	lem_in

SRC  	=	lemin.c											\
		error_manager.c										\
		load_lemin/load_lemin.c									\
		load_lemin/load_room.c									\
		load_lemin/load_pipe.c									\
		linked_list/linked_list_basic.c								\
		linked_list/linked_list_display.c							\
		linked_list/linked_list_removal.c							\
		algorithm/algorithm.c									\
		algorithm/ways_finder_and_sorter/manage_stack_ways/func_stack_ways.c			\
		algorithm/ways_finder_and_sorter/manage_stack_ways/func_ways.c				\
		algorithm/mover_ants/advance_ants.c							\
		algorithm/ways_finder_and_sorter/manage_act/copy_way.c					\
		algorithm/ways_finder_and_sorter/manage_act/del_way_in_map_by_pos.c			\
		algorithm/ways_finder_and_sorter/manage_act/sort_ways.c					\
		algorithm/ways_finder_and_sorter/manage_act/uncheck_state_worst_way.c			\
		algorithm/ways_finder_and_sorter/manage_comparison/comparing_a_way_relative_map.c	\
		algorithm/ways_finder_and_sorter/manage_comparison/comparison_on_ways.c			\
		algorithm/ways_finder_and_sorter/search_best_ways_in_stack.c				\

OBJ  	=	$(addprefix src/, $(SRC:.c=.o))

RM 	=	rm -f

CC 	=	gcc

CFLAGS	+=	-O2 #-W -Wall -Wextra -Werror
CFLAGS	+=	-I./include -I./lib/src/include

LDFLAGS	+=	-L./lib/ -lmy

DEBUG	=	no

OPTI	=	yes

ifeq	($(OPTI), yes)

CFLAGS	+=	-Ofast

endif

ifeq	($(DEBUG), yes)

CFLAGS	+=	-g -g3 -ggd

endif

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(MAKE) -C lib/src
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) -L./lib/ -lmy

clean	:
		$(MAKE) -C lib/src clean
		$(RM) $(OBJ)

fclean	:	clean
		$(MAKE) -C lib/src fclean
		$(RM) $(NAME)

re	:	fclean all
