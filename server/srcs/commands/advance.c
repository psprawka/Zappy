/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 13:13:01 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

#define WIDTH g_server->map->width
#define HEIGHT g_server->map->height

int		command_advance(void *object, t_action_arg *arg)
{
	t_player	*player;
	
	player = (t_player *)object;
	if (player->direction & NORTH)
		player->y = (!player->y) ? HEIGHT - 1 : player->y - 1;
	if (player->direction & EAST)
		player->x = (player->x == WIDTH - 1) ? 0 : player->x + 1;
	if (player->direction & SOUTH)
		player->y = (player->y == HEIGHT - 1) ? 0 : player->y + 1;
	if (player->direction & WEST)
		player->x = (!player->x) ? WIDTH - 1 : player->x - 1;

	if (send(player->fd, MSG_OK, ft_strlen(MSG_OK), 0) == -1)
		return (error(0, "Send", false));
	arg = (void *)arg;
	return (EXIT_SUCCESS);
}

//i think this one is oke
