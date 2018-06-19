/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 00:27:15 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_right(void *entity, char *msg)
{
	printf("%sPlayer %d -> [right]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	P_ENTITY->direction = (P_ENTITY->direction == WEST) ? NORTH : P_ENTITY->direction * 2;
	P_ENTITY->requests_nb--;
	if (send(P_ENTITY->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
		return (error(0, "Send", false));
	player_position(g_server.graphic_fd, P_ENTITY);
	return (EXIT_SUCCESS);
}

