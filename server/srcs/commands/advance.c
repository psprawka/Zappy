/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 06:15:19 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

#define WIDTH g_server.map->width
#define HEIGHT g_server.map->height

int		command_advance(void *entity, char *msg)
{
	printf("%sPlayer [%d] -> [advance]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	if (P_ENTITY->direction & NORTH)
		P_ENTITY->y = ft_modulo((P_ENTITY->y + 1), HEIGHT);
	if (P_ENTITY->direction & EAST)
		P_ENTITY->x = ft_modulo(P_ENTITY->x + 1, WIDTH);
	if (P_ENTITY->direction & SOUTH)
		P_ENTITY->y = ft_modulo(P_ENTITY->y - 1, HEIGHT);
	if (P_ENTITY->direction & WEST)
		P_ENTITY->x = ft_modulo(P_ENTITY->x - 1, WIDTH);
	P_ENTITY->requests_nb--;
	if (send(P_ENTITY->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
		return (error(0, "Send advance", false));
	notify_player_position(0, P_ENTITY);
	return (EXIT_SUCCESS);
}
