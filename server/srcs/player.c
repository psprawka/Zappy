/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:03:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 20:17:33 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static void	del_queue(t_player *player, t_server *server)	
{
	t_node	*tmp;
	t_node	*node;
	t_node	*prev;

	node = server->events->first;
	prev = NULL;
	while (node)
	{
		if (((t_event *)node->content)->player == player)
		{
			if (prev)
				prev->next = node->next;
			tmp = node;
			node = node->next;
			free(tmp);
		}
		else
		{
			prev = node;
			node = node->next;
		}
	}
}

void		player_quit(t_player *player, t_server *server)
{
	struct kevent	evDel;

	ft_printf("Player [%d] quit\n", player->fd);
	command_death(player, server);
	close(player->fd);
	EV_SET(&evDel, player->fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
	if (kevent(server->kfd, &evDel, 1, 0, 0, NULL) == -1)
		error(6, "kevent error", false);
	if (server->events)
		del_queue(player, server);
	free(player);
}
