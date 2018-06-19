/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:32:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 02:14:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Function time_compare_event determines which one time struct is "bigger"
**	and it is dedicated to t_event struct as comparing function in pqueue.
**	If first time value is "smaller" or struct have the same time, value
**	0 is returned. If first value is "bigger", value 1 is returned.
*/
int				time_compare_events(t_node *node1, t_node *node2)
{
	t_event		*first;
	t_event		*second;

	first = (t_event *)node1->data;
	second = (t_event *)node2->data;

	if (first->event_time->tv_sec != second->event_time->tv_sec)
		return (first->event_time->tv_sec > second->event_time->tv_sec);
	return (first->event_time->tv_usec > second->event_time->tv_usec);
}

/* 
**	----------------------------------------------------------------------------------
**	i know they are the same but im too tired to fix it now, ill do it in the morning
*/

/*
**	Function time_compare determines which one time struct is "bigger".
**	If first time value is "smaller" or struct have the same time, value
**	0 is returned. If first value is "bigger", value 1 is returned.
*/

int		time_compare(struct timeval *first, struct timeval *second)
{
	if (!first)
		return (0);
	if (!second)
		return (1);
	if (!first && !second)
		return (-1);
	if (first->tv_sec != second->tv_sec)
		return (first->tv_sec > second->tv_sec);
	return (first->tv_usec > second->tv_usec);
}

/*
**	Function time_compare determines which one time struct is "bigger".
**	Time struct that will happen sooner is returned.
*/
struct timeval	*time_compare2(struct timeval *first, struct timeval *second)
{
	if (!first && !second)
		return (NULL);
	if (!first)
		return (second);
	if (!second)
		return (first);

	if (first->tv_sec != second->tv_sec)
		return (first->tv_sec > second->tv_sec ? second : first);
	return (first->tv_usec > second->tv_usec ? second : first);
}
/*
**	--------------------------------------------------------------------------------
*/

/*	Funtion next_event_time goes to events queue and gets its first node's time,
**	then time is returned or NULL in case of an empty queue.
*/
static struct timeval	*next_event_time(void)
{
	t_event			*equeue_first;

	equeue_first = NULL;
	if (g_server.events && g_server.events->first)
		equeue_first = (t_event *)g_server.events->first->data;		
	return (equeue_first ? equeue_first->event_time : NULL);
}

/*
**	Function set_time_alarm is used in function main_game_loop located
**	in main.c file; it sets an alarm (timeout) for select function.
**
**	1. Nextevent timeval struct is set and initialized to 0. Curr timeval
**		struct holds current time now.
**	2. Nextevent variable is set to the soonest coming event or to NULL
**		if there is no events in queue.
**	3. Based on execution time (nextevent) and current time (curr)
**		count actual time to execute (nextevent - curr);
*/
struct timeval			*set_time_alarm(void)
{
	struct timeval	*nextevent;
	struct timeval	curr;

	if (gettimeofday(&curr, NULL) == EXIT_FAILURE ||
		!(nextevent = ft_memdup(next_event_time(), sizeof(struct timeval))))
		return (NULL);
	if ((nextevent->tv_sec - curr.tv_sec) < 0)
		return (NULL);
	if ((nextevent->tv_usec - curr.tv_usec) < 0)
	{
		if ((nextevent->tv_sec - (curr.tv_sec + 1)) < 0)
			return (NULL);
		nextevent->tv_sec -= (curr.tv_sec + 1);
		nextevent->tv_usec += (1000000 - curr.tv_usec);
	}
	else
	{
		nextevent->tv_usec -= curr.tv_usec;
		nextevent->tv_sec -= curr.tv_sec;
	}
	return (nextevent);
}
