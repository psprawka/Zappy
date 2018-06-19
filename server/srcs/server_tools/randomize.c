/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:54:20 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/15 02:08:36 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_server.h"

/*	There are 4 directions:
**	NORTH	1
**	EAST	2
**	SOUTH	4
**	WEST	8
*/

int		rand_direction(void)
{
	return (1 << (rand() & 3));
}

void	rand_position(t_player *player)
{
	player->x = rand() % g_server.map->width;
	player->y = rand() % g_server.map->height;
}
