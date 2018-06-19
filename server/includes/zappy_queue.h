/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_queue.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:39:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 05:00:52 by psprawka         ###   ########.fr       */
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

#endif
