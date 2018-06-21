/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_greeting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:22:11 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 07:47:27 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static void		enw_greeting(int fd)
{
	int			i;
	t_node		*node;
	t_egg		*egg;

	i = 0;
	while (g_server.teams[i])
	{
		node = ((g_server.teams[i])->egg_queue)->first;
		while (node)
		{
			egg = ((t_egg *)(node->data));
			notify_egg_laid(g_entity[egg->father_fd], egg);
			node = node->next;
		}
		i++;
	}
}

static void		send_players(int fd)
{
	int		i;

	i = 0;
	while (i < FD_SETSIZE)
	{
		if (g_client_type[i] == T_PLAYER)
			notify_new_player(fd, g_entity[i]);
		i++;
	}
}

void			send_graphic_greeting(int fd)
{
	map_size(fd);
	send_timeunit(fd);
	send_mapcontents(fd);
	send_teams(fd);
	send_players(fd);
	enw_greeting(fd);
}
