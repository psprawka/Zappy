/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_queue.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:39:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/16 00:23:44 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_PQUEUE_H
# define ZAPPY_PQUEUE_H

#include "zappy.h"

typedef struct	s_event
{
	struct timeval		*event_time;
	char				*msg;
	void				*entity;
	int					(*fct)(void *entity, char *msg);
}				t_event;

typedef struct	s_death
{
	struct timeval		*death_time;
	void				*entity;
}				t_death;

#endif
