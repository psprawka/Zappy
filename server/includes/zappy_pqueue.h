/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_pqueue.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:39:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 16:34:22 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_PQUEUE_H
# define ZAPPY_PQUEUE_H

#include "zappy.h"

/*
**	pevents -> priority queue of events all players requested
*/

typedef struct	s_node
{
	void			*content;
	struct s_node	*next;
}				t_node;

// typedef struct	s_queue
// {
// 	t_node			*first;
// 	t_node			*last;
// }				t_queue;

typedef struct	s_pevent
{
	// int					time;
	struct timeval		*event_time;
	char				*msg;
	// int					type;
	// t_player			*player;
	t_client			*client;
	// int					(*fct)(t_player *player, t_server *serv, t_action_arg *arg);
	int					(*fct)(void *object, t_action_arg *arg);

	void				*object;	// Object can be a player or an egg
	struct s_pevent		*next;
}				t_pevent;

typedef struct	s_pdeath
{
	struct timeval		*death_time;
	// t_player			*player;
	void				*object;		// Object can be a player or an egg
	struct s_pdeath		*next;
}				t_pdeath;


#endif
