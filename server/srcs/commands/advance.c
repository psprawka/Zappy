/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/31 17:49:23 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	command_advance(t_player *player, t_server *serv)
{
	if (player->direction & NORTH)
		player->position = (player->position % serv->map->y == 1) ?
		player->position + serv->map->y - 1 : player->position--;
		
	if (player->direction & EAST)
		player->position = (player->position % serv->map->y == 0) ?
		player->position - serv->map->y + 1 : player->position++;
		
	if (player->direction & SOUTH)
		player->position = (player->position % serv->map->y == 1) ?
		player->position + serv->map->y - 1 : player->position--;
		
	if (player->direction & WEST)
		player->position = (player->position % serv->map->y == 1) ?
		player->position + serv->map->y - 1 : player->position--;
		
	send(player->fd, MSG_OK, ft_strlen(MSG_OK), 0);
}
