/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:56:59 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 04:37:39 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

#define EVENT	((t_event *)event)

/*
**	Functions below free all memory allocated on heap within a requested free.
*/
void			free_event(void *event)
{
	if (!event)
		return ;
	if (EVENT->msg)
		free(EVENT->msg);
	if (EVENT->event_time)
		free(EVENT->event_time);
	free(EVENT);
}

void			free_player(int fd)
{
	if (!g_entity[fd])
		return ;

	if (((t_player *)g_entity[fd])->last_request)
		free(((t_player *)g_entity[fd])->last_request);
	free(g_entity[fd]);
}

void			free_eggs(void *egg)
{
	if (egg)
		free(egg);
}

static void		free_teams(void)
{
	int	i;

	i = 0;
	while (i < g_server.teamcount)
	{
		ft_free_queue(g_server.teams[i]->egg_queue, free_eggs);
		free(g_server.teams[i]);
		i++;
	}
	free(g_server.teams);
}

static void		free_map(void)
{
	int 	xfree;
	int		yfree;

	xfree = 0;
	while (xfree < g_server.map->width)
	{
		yfree = 0;
		while (yfree < g_server.map->height)
			free(g_server.map->squares[xfree][yfree++]);
		free(g_server.map->squares[xfree++]);
	}
	free(g_server.map);
}

void			free_server(void)
{
	int		i;

	i = 0;
	// free_map();
	free_teams();
	ft_free_queue(g_server.events, free_event);
	free(g_server.buff);
	while (i < FD_SETSIZE)
		free_player(i++);
}