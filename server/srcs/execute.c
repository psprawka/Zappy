/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:55:18 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 07:11:12 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

#define TEMP_EVENT   ((t_event *)(g_server.events->first->data))

/*
**	Function execute_events goes to priorty queue and executes events
**	that are happening or should already happen. It iterates throught
**	events priority queue until it reaches the end of a queue OR finds
**	an event that will happen in the future.
**
**	For all checked events:
**	-> curr timeval struct gets and holds current time,
**	-> event is set to the very first event in queue,
**	-> times are compared in time_compare (return 0 when first argument
**		is "smaller" or equal to second and 1 when first one is "bigger")
**		and if event didn't happen yet while loop breaks.
**	-> function assigned to an event is called,
**	-> an event is popped from queue and freed.
*/
int		execute_events(void)
{
	struct timeval	curr;
	t_event			*event;

	while (g_server.events)
	{
		if (gettimeofday(&(curr), NULL) == EXIT_FAILURE)
			return (error(0, "Gettimeofday [execute_events]", true));

		event = (t_event *)ft_top_queue(g_server.events);
		if (!event || time_compare(event->event_time, &curr))
			break ;
			
		if (event->entity)
			TEMP_EVENT->fct(TEMP_EVENT->entity, TEMP_EVENT->msg);
		free(ft_pop_queue(&g_server.events));
		free_event(event);
	}
	return (EXIT_SUCCESS);
}