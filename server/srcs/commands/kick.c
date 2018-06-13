/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:03:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 19:16:33 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_kick(t_player *player, t_server *serv)
{
		int	i;
	int	tmp;

	i = 0;
	// while (i < FD_SETSIZE)
	// {
	// 	if ((!server->clients[i] || server->clients[i]->type != player) && ++i)
	// 		continue;
	// 	if (((t_player *)server->clients[i])->position->x == player_conn->position->x &&
	// 		((t_player *)server->clients[i])->position->y == player_conn->position->y &&
	// 		((t_player *)server->clients[i])->fd != player_conn->fd)
	// 	{
	// 		tmp = ((t_player *)server->clients[i])->direction;
	// 		((t_player *)server->clients[i])->direction = player_conn->direction;
	// 		command_advance((t_player *)server->clients[i], server);
	// 		((t_player *)server->clients[i])->direction = tmp;
	// 	}
	// 	i++;
	// }
	if (send(player->fd, MSG_OK, sizeof(MSG_OK), 0) == -1)
		return(error(0, "Send", false));
	return (EXIT_SUCCESS);
}
