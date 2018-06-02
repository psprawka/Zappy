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

int rand_direction(void)
{
	return (1 << (rand() & 3));
}

int rand_position(t_map *map)
{
	return (rand() % (map->height * map->width));
}
