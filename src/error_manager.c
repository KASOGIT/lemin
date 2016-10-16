/*
** lemin_error_manager.c for lemin in /home/benjamin/rendu/C/CPE/CPE_2014_lemin
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Fri Apr 17 14:00:09 2015 Benjamin Rascol
** Last update Sun Oct 16 13:44:33 2016 
*/

#include "lemin.h"

static t_error	data[] =
  {
    {ERROR_LEMIN, INVALID_NB_ANT,
     "Lemin Error : Invalid number of ant.\n"},
    {ERROR_LEMIN, NO_DATA,
     "Lemin Error : No data detected for ./lem-in.\n"},
    {ERROR_LEMIN, UNINITIALISED_ROOT,
     "Lemin Error : Uninitialised root.\n"},
    {ERROR_LEMIN, MALLOC_FAILED,
     "Lemin Error : Malloc failed. Impossible happened.\n"},
    {ERROR_LEMIN, UNDEFINED_START_END,
     "Lemin Error : Start or End may be uninitialized.\n"},
    {WARNING_IGNORE, INVALID_INSTRUCTION,
     "Lemin Warning : Invalid room specification.\n"},
    {WARNING_LEMIN, INVALID_POSITION,
     "Lemin Warning : Positive and numeric position number is requiered.\n"},
    {WARNING_IGNORE, INVALID_PIPE,
     "Lemin Warning : Invalid statement of pipe.\n"},
    {WARNING_LEMIN, PIPE_SPECIFICATION,
     "Lemin Warning : START and END can not be in a pipe.\n"},
    {WARNING_LEMIN, UNKNOW_PARAM,
     "Lemin Warning : Unknow parameter.\n"},
    {WARNING_LEMIN, UNKNOW_ROOM_NAME,
     "Lemin Warning : Unknow room name on pipe link.\n"},
    {WARNING_LEMIN, MULTIPLE_DEFINE_START_END,
     "Lemin Warning : Multiple definition of START and/or END.\n"},
    {WARNING_IGNORE, MULTIPLE_PIPE_DEFINITION,
     "Lemin Warning : Multiple definition of a same pipe.\n"},
    {0, 0, NULL}
  };

int	error_manager(char cur_sig, char *str, int cur_line)
{
  int	i;

  i = 0;
  while (data[i].error_sig != 0 && data[i].error_sig != cur_sig)
    {
      i++;
    }
  if (data[i].error_msg != NULL)
    {
      fprintf(stderr, "\e[101m/!\\\e[0m ");
      fprintf(stderr, "%s", data[i].error_msg);
      if (str != NULL)
	fprintf(stderr, "At line \e[1mn°%d \e[0m: \"\e[104m%s\e[0m\"\n",
	       cur_line, str);
      if (data[i].error_ret == WARNING_LEMIN)
	fprintf(stderr, "Parsing Stopped.\n");
      else if (data[i].error_ret == ERROR_LEMIN)
	fprintf(stderr, "Program Stopped.\n");
      return (data[i].error_ret);
    }
  return (ERROR_LEMIN);
}
