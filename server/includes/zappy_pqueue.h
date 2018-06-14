/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_pqueue.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:39:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 21:05:26 by tle-huu-         ###   ########.fr       */
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
	struct timeval		delaytime;
	char				*msg;
	t_player			*player;

	int					(*fct)(t_player *player, t_server *serv);
	struct s_pevent		*next;
}				t_pevent;

#endif
