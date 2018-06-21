/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 06:16:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_left(void *entity, char *msg)
{
	printf("%sPlayer [%d] -> [left]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	P_ENTITY->direction = (P_ENTITY->direction / 2 == 0) ? WEST : P_ENTITY->direction / 2;
	P_ENTITY->requests_nb--;
	if (send(P_ENTITY->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
		return (error(0, "Send [left]", false));
	notify_player_position(0, P_ENTITY);
	return (EXIT_SUCCESS);
}

