/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:03:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 23:50:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

#define WIDTH serv->map->width
#define HEIGHT serv->map->height

void	send_kick_message(t_server *serv, t_player *player, int kicked_from, int facing)
{
	int		k;
	k = 1;
	while (facing != kicked_from)
	{
		k += 2;
		if (facing & WEST)
			facing = SOUTH;
		else if (facing & SOUTH)
			facing = EAST;
		else if (facing & EAST)
			facing = NORTH;
		else if (facing & NORTH)
			facing = WEST;
	}
	strcpy(serv->buff, "moving ");
	strcat(serv->buff, ft_itoa(k));
	strcpy(serv->buff, "\n");
	if (send(player->fd, serv->buff, ft_strlen(serv->buff), 0) == -1)
		error(0, "Send", false);
}

void	kick_player(t_server *serv, t_player *kicker, t_player *to_kick)
{
	if (kicker->direction & NORTH)
	{
		to_kick->y = (!to_kick->y) ? HEIGHT - 1 : to_kick->y - 1;
		send_kick_message(serv, to_kick, SOUTH, to_kick->direction);
	}
	else if (kicker->direction & EAST)
	{
		to_kick->x = (to_kick->x == WIDTH - 1) ? 0 : to_kick->x + 1;
		send_kick_message(serv, to_kick, WEST, to_kick->direction);
	}
	else if (kicker->direction & SOUTH)
	{
		to_kick->y = (to_kick->y == HEIGHT - 1) ? 0 : to_kick->y + 1;
		send_kick_message(serv, to_kick, NORTH, to_kick->direction);
	}
	else if (kicker->direction & WEST)
	{
		to_kick->x = (!to_kick->x) ? WIDTH - 1 : to_kick->x - 1;
		send_kick_message(serv, to_kick, EAST, to_kick->direction);
	}
}

int		command_kick(t_player *player, t_server *serv)
{
	int	i;
	int	tmp;

	i = 0;
	printf("Player %d has sent command [kick]\n", player->fd);
	while (i < FD_SETSIZE)
	{
		if (!serv->players[i] && ++i)
			continue;
		if (serv->players[i]->x == player->x && serv->players[i]->y == player->y
			&& serv->players[i]->fd != player->fd)
				kick_player(serv, player, serv->players[i]);
		i++;
	}
	if (send(player->fd, MSG_OK, sizeof(MSG_OK), 0) == -1)
		return(error(0, "Send", false));
	return (EXIT_SUCCESS);
}

//i think this one is fine
