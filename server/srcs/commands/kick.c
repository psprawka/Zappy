/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:03:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 20:51:24 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_kick(t_player *player, t_server *serv)
{
	int	i = 0;
	
	while (i < FD_SETSIZE)
	{
		if (!serv->players[i] && ++i)
			continue;
		if (serv->players[i]->position->x == player->position->x &&
			serv->players[i]->position->y == player->position->y &&
			serv->players[i]->fd != player->fd)
			command_advance(player, serv);
		i++;
	}
	return (1);
}
