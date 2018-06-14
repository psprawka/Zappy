/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_pqueue.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:39:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 21:13:25 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_PQUEUE_H
# define ZAPPY_PQUEUE_H

#include "zappy.h"

/*
**	pevents -> priority queue of events all players requested
*/

typedef struct	s_pevent
{
	int					time;
	struct timeval		*event_time;
	char				*msg;
	t_player			*player;

	int					(*fct)(t_player *player, t_server *serv);
	struct s_pevent		*next;
}				t_pevent;

typedef struct	s_pdeath
{
	struct timeval		*death_time;
	t_player			*player;
	struct s_pdeath		*next;
}				t_pdeath;

#endif
