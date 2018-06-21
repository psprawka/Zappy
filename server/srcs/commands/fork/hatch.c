/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hatch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:09:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 05:32:02 by psprawka         ###   ########.fr       */
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
	notify_hatch_egg(E_ENTITY);
	return (EXIT_SUCCESS);
}
