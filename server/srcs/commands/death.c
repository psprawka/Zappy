/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:22 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 03:35:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_death(void *entity, char *msg)
{
	if (!entity)
		return (EXIT_FAILURE);
	printf("%sPlayer [%d] has died%s\n", PINK, P_ENTITY->fd, NORMAL);
	if (P_ENTITY->team)
		P_ENTITY->team->connected--;
	if (send(P_ENTITY->fd, MSG_DEATH, ft_strlen(MSG_DEATH), 0) == -1)
		return (error(0, "Send [death]", false));
	return (EXIT_SUCCESS);
}
