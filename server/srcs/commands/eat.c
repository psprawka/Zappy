/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 22:49:02 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:17:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_eat(void *entity, char *msg)
{
	if (!entity)
		return (EXIT_FAILURE);
	if (g_entity[P_ENTITY->fd] && P_ENTITY->inventory[0] > 0)
	{
		printf("%sPlayer [%d]-> [EATING]%s\n", ORANGE, P_ENTITY->fd, NORMAL);
		P_ENTITY->inventory[0]--;
		add_event(entity, T_NONDEF, 13, "eat");
		send_inventory(0, P_ENTITY);
	}
	else
	{
		command_death(P_ENTITY, NULL);
		client_death(P_ENTITY->fd);
	}
	return (EXIT_SUCCESS);
}
