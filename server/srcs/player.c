/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:03:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 02:29:32 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	player_quit(t_player *player, t_server *server)
{
	int	i;
	int	local_max;

	ft_printf("Player [%d] quit\n", player->fd);
	command_death(player, server);
	close(player->fd);
	FD_CLR(player->fd, &(server->server_fds));
	i = 0;
	local_max = 0;
	while (i < server->max)
	{
		if (FD_ISSET(i, &(server->server_fds)) && i >= local_max)
			local_max = i + 1;
		i++;
	}
	server->max = local_max;
	free(player);
}
