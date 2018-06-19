/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hatch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:09:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 01:43:44 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int			command_hatch(void *entity, char *msg)
{
	if (!entity)
		return (EXIT_FAILURE);
	E_ENTITY->hatched = 1;
	if (E_ENTITY->team)
		E_ENTITY->team->allowed_eggs++;
	notify_hatchegg(g_server.graphic_fd, E_ENTITY);
	return (EXIT_SUCCESS);
}
