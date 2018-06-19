/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:25:38 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 03:52:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Function init_event simply creates and initializes an event, assigns all
**	the values and sets player's last request. Returns NULL upon failure.
*/
t_event		*init_event(void *entity, struct timeval *time, int (*fct)(void *, char *), char *msg)
{
	t_event				*new;

	if (!(new = ft_memalloc(sizeof(t_event))))
		return (NULL);
	if (msg)
		new->msg = ft_strdup(msg);
	new->entity = entity;
	new->fct = fct;
	new->event_time = time;
	return (new);
}

/*
**	Event_time funciton:
**	1. Gets and holds current time in curr struct.
**	2. Last request is set to player's latest required event time.
**	3. If player didn't request anything or a request already happened,
**		last request is now, thus it's assigned to current time.
**	4. Calculations are made based on the time requested event takes
**		(g_events_ai[itable].time);
**	5. Time of execution is returned.
*/
struct timeval	*event_time(void *entity, int type, int itable)
{
	struct timeval	*last_request;
	struct timeval	curr;

	if (gettimeofday(&(curr), NULL) == EXIT_FAILURE)
	{
		error(0, "Gettimeofday [event_time]", true);
		return (NULL);
	}
	last_request = NULL;
	if (type == T_PLAYER)
		last_request = ((t_player *)entity)->last_request;
	if (!last_request || !time_compare(last_request, &curr))
		last_request = &curr;
	last_request->tv_sec += g_events_ai[itable].time * g_server.time.tv_sec;
	last_request->tv_usec += g_events_ai[itable].time * g_server.time.tv_usec;
	last_request->tv_sec += (last_request->tv_usec) / 1000000;
	last_request->tv_usec %= 1000000;
	return (last_request);
}

/*
**	An add_event function adds new requested event to events pqueue if player didn't
**	already request MAX_REQUEST_NB events. Then it determines what time an event should
**	be executed at (event_time() function) and creates an event (init_event() function).
**	t_node *node is initialized with information about an event and pushed to pqueue.
**	Number of player's requests increases and EXIT_SUCCESS is returned.
*/
int		add_event(void *entity, int type, int itable, char *msg)
{
	struct timeval	*exec_time;
	t_event			*new;
	t_node			*node;

	if (type == T_PLAYER && P_ENTITY->requests_nb == MAX_REQUEST_NB)
		return (EXIT_FAILURE);
	exec_time = ft_memdup(event_time(entity, type, itable), sizeof(struct timeval));
	if (!(new = init_event(entity, exec_time, g_events_ai[itable].fct, msg)))
		return (EXIT_FAILURE);
	if (type == T_PLAYER)
	{
		P_ENTITY->last_request = ft_memdup(new->event_time, sizeof(struct timeval));
		P_ENTITY->requests_nb++;
	}
	if (!(node = ft_init_node(new, sizeof(new))))
	{
		free_event(new);
		return (EXIT_FAILURE);	
	}
	ft_push_pqueue(&(g_server.events), node, time_compare_events);
	if (g_server.print_queue == true)
		printqueue();
	return (EXIT_SUCCESS);
}
