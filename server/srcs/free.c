/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:56:59 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 00:47:41 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Functions below free all memory allocated on heap within a requested free.
*/
void		free_event(t_event *event)
{
	if (!event)
		return ;
	if (event->msg)
		free(event->msg);
	if (event->event_time)
		free(event->event_time);
	free(event);
}

void		free_player(int fd)
{
	if (!g_entity[fd])
		return ;

	if (((t_player *)g_entity[fd])->last_request)
		free(((t_player *)g_entity[fd])->last_request);
	free(g_entity[fd]);
}