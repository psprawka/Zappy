/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:03:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 15:36:08 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	player_quit(t_player *player, t_server *server)
{
	int				i;
	struct kevent	evDel;

	ft_printf("Player [%d] quit\n", player->fd);
	command_death(player, server);
	close(player->fd);
	EV_SET(&evDel, player->fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
	if (kevent(server->kfd, &evDel, 1, NULL, 0, NULL) == -1)
		error(6, "kevent error", false);
	free(player);
}
