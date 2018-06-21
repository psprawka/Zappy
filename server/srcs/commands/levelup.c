/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levelup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 21:36:42 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 06:15:30 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_levelup(void *entity, char *msg)
{
	P_ENTITY->level++;
	ft_bzero(g_server.buff, SERV_BUFF_SIZE);
	ft_strcpy(g_server.buff, "current level: ");
	ft_strcat(g_server.buff, ft_itoa(P_ENTITY->level));
	ft_strcat(g_server.buff, "\n");
	P_ENTITY->requests_nb--;
	P_ENTITY->incantation = false;
	if (send(P_ENTITY->fd, g_server.buff, ft_strlen(g_server.buff), 0) == -1)
		return (error(0, "Send [levelup]", true));
	notify_player_level(0, P_ENTITY);
	return (EXIT_SUCCESS);
}
