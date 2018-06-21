/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:39:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 08:21:26 by psprawka         ###   ########.fr       */
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


struct timeval	*time_compare2(struct timeval *first, struct timeval *second);

#endif

//	todo:
//	-> when someone levels up check resources,
//	-> joining teams don't work properly,
//	-> parse commands from graphical,
//	-> accepts commands that are incorrect (kickdshshjaahads is accepted),
//	-> see and inv have some stuff inside and not sure why.

