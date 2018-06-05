/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 22:44:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

#define WIDTH	serv->map->width
#define HEIGHT	serv->map->height

int 	command_advance(t_player *player, t_server *server)
{
	ft_printf("facing: [%s], %d -> ", (player->direction & WEST ? "WEST" :
	(player->direction & EAST ? "EAST" : (player->direction & SOUTH ? "SOUTH" : "NORTH"))),  player->position->x * player->position->y);
	
	if (player->direction & NORTH)
	{
		if (!player->position->y)
			player->position->y = (server->map->width - 1);
		else
			player->position->y--;
	}
	else if (player->direction & EAST)
	{
		if (player->position->x == (server->map->width - 1))
			player->position->x = 0;
		else
			player->position->x++;
	}
	else if (player->direction & SOUTH)
	{
		if (player->position->y == (server->map->height - 1))
			player->position->y = 0;
		else
			player->position->y++;
	}
	else if (player->direction & WEST)
	{
		if (!player->position->x)
			player->position->x = (server->map->width - 1);
		else
			player->position->x--;
	}
	if (send(player->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
		printf("Error sending: \"%s\"\n", strerror(errno));
	ft_printf("%d\n", xytocoordinate(player->position->x, player->position->y));
	return (EXIT_SUCCESS);
}

// 1   2   3   4   5   6   7   8   9   10  11
// 12  13  14  15  16  17  18  19  20  21  22
// 23  24  25  26  27  28  29  30  31  32  33
// 34  35  36  37  38  39  40  41  42  43  44
// 45  46  47  48  49  50  51  52  53  54  55
