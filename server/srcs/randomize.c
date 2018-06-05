/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:54:20 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 15:44:40 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_server.h"

/*	There are 4 directions:
**	NORTH	1
**	EAST	2
**	SOUTH	4
**	WEST	8
*/

int			rand_direction(void)
{
	return (1 << (rand() & 3));
}

/*
** This won't work yet as we don't use squares!
** ToDo: Can this ever fail? Can rand() ever fail?
** If so, how do we calculate it?
*/

t_square	*rand_position(t_map *map)
{
	int			x;
	int			y;

	x = rand() % map->width;
	y = rand() % map->height;
	return (&(map->squares[x][y]));
}
