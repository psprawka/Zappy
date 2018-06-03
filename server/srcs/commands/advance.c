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

int		command_advance(t_player *player, t_server *serv)
{
	ft_printf("facing: [%s], %d -> ", (player->direction & WEST ? "WEST" :
	(player->direction & EAST ? "EAST" : (player->direction & SOUTH ? "SOUTH" : "NORTH"))),  player->position);
	
	if (player->direction & NORTH)
		player->position = (player->position - WIDTH < 1) ?
		WIDTH * HEIGHT - WIDTH + player->position : player->position - WIDTH;
		
	if (player->direction & EAST)
		player->position = (player->position % WIDTH == 0) ?
		player->position - WIDTH + 1 : player->position + 1;
		
	if (player->direction & SOUTH)
		player->position = (player->position + WIDTH > WIDTH * HEIGHT) ?
		player->position % (WIDTH * (HEIGHT - 1)) : player->position + WIDTH;
		
	if (player->direction & WEST)
		player->position = (player->position % WIDTH == 1) ?
		player->position + WIDTH - 1 : player->position - 1;
	if (send(player->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
		error(0, "Send", false);
		
	ft_printf("%d\n", player->position);
	return (1);
}

// 1   2   3   4   5   6   7   8   9   10  11
// 12  13  14  15  16  17  18  19  20  21  22
// 23  24  25  26  27  28  29  30  31  32  33
// 34  35  36  37  38  39  40  41  42  43  44
// 45  46  47  48  49  50  51  52  53  54  55
