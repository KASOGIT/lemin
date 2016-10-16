/*
** main.c for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Tue Apr 14 17:51:27 2015 Benjamin Rascol
** Last update Sun May  3 19:13:30 2015 adam soto
*/

#include "lemin.h"

/*
** Init t_data structure.
*/

static int	init_lemin(t_data *anthill)
{
  if (linked_list_init_root(&(anthill->room_list)) == ERROR_LEMIN)
    return (ERROR_LEMIN);
  linked_list_init_root(&(anthill->room_end));
  linked_list_init_root(&(anthill->room_start));
  anthill->nbr_ant = 0;
  return (SUCCESS);
}

/*
** Main for the win.
*/

int		main()
{
  t_data	anthill;

  if (init_lemin(&anthill) == ERROR_LEMIN
      || load_lemin(&anthill) == ERROR_LEMIN)
    return (ERROR_LEMIN);
  printf("-------------- ALGO --------------\n");
  algorithm(&anthill);
  return (SUCCESS);
}
