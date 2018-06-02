/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/01 20:08:42 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	command_advance(t_player *player, t_server *serv)
{
	if (player->direction & NORTH)
		player->position = (player->position - serv->map->x < 1) ?
		serv->map->x * serv->map->y - serv->map->x + player->position
		: player->position - serv->map->x;
		
	if (player->direction & EAST)
		player->position = (player->position % serv->map->y == 0) ?
		player->position - serv->map->y + 1 : player->position++;
		
	if (player->direction & SOUTH)
		player->position = (player->position + serv->map->x > serv->map->x * serv->map->y) ?
		player->position % serv->map->x * serv->map->y : player->position + serv->map->x;
		
	if (player->direction & WEST)
		player->position = (player->position % serv->map->y == 1) ?
		player->position + serv->map->y - 1 : player->position--;
		
	send(player->fd, MSG_OK, ft_strlen(MSG_OK), 0);
}
