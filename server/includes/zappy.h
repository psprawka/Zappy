/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:39:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 07:58:49 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_H
# define ZAPPY_H

# include <unistd.h>
# include <stdio.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <errno.h>
# include <term.h>
# include <curses.h>
# include "libft.h"
# include <string.h>

# include "zappy_map.h"
# include "zappy_commands.h"
# include "zappy_queue.h"
# include "zappy_client.h"
# include "zappy_define.h"
# include "zappy_server.h"
# include "zappy_prototypes.h"
# include "zappy_graphic.h"

extern uint8_t 		g_client_type[FD_SETSIZE];	/* holds clients type */
extern void			*g_entity[FD_SETSIZE];		/* holds clients data */
extern t_events		g_events_ai[];				/* gathers all ai events */
extern t_server		g_server;

char	*g_ressources[8];

typedef struct	s_opt
{
	char		opt;
	int			(*fct)(char **av, int *i);
}				t_opt;

//test to remove /////////////////////////////////////////////////
void			print_map(t_server *server, int x, int y);
void			printf_pqueue(t_queue *head, char *color);
struct timeval	*time_compare2(struct timeval *first, struct timeval *second);
void			printqueue(void);

#endif

//	todo:
//	-> everything with death queue												3h		~
//	-> get rid of strdup variables in time.c and event.c						30-60mins ~
//	-> add terences code														3-5h	~
//	-> if time left clean libft
//	-> send Theo bct when player put or take something							15mins
//	-> free node in add_event func in event.c file upon failure 				20mins	~
//	-> when player's event is happening substract players->requests;			5mins	~
//	-> client.c new client function has to accept all object (ai, gui, egg)		3-5h	~
//	-> client death has to remove all player commands from queue.				20mins	~
//	-> make sure map works so init_map 											1h		~
//	-> write food and stones generator											20mins	~
//	-> when client leaves program quit differently based on its type			20mins	~
//	-> when entity leaves remove them from entity array							20mins	~
//	-> eat event death queue 															~
//	-> there has to be an special function for an egg to die 							~
//	-> eggs																				~
//	-> incantation
//	-> fork																				~
//	-> broadcast
//	-> graphic queue (I don't know if it's done already (Terence?))
//	-> fix joining to team (when "pol" typed it will join "pola")						~
//	-> player can request up to 10 events and now its more so it doesnt substract somewhere	~
//	-> sometimes connect_nbr is incorrect (when it comes to eggs)
//	-> when player moves or is kicked out change players on the square
