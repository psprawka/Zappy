/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:06 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 03:53:46 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_connect_nbr(void *entity, char *msg)
{
	// printf("Player %d has sent command [connect_nbr] [%d][%d]\n", P_ENTITY->fd, P_ENTITY->team->connected, P_ENTITY->team->allowed_eggs);
	printf("%sPlayer [%d] -> [connect_nbr]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	ft_bzero(g_server.buff, 2048);
	ft_strcpy(g_server.buff, ft_itoa(P_ENTITY->team->max_players + P_ENTITY->team->allowed_eggs - P_ENTITY->team->connected + 1));
	ft_strcat(g_server.buff, "\n");
	P_ENTITY->requests_nb--;
	if (send(P_ENTITY->fd, g_server.buff, ft_strlen(g_server.buff), 0) == -1)
		return (error(0, "Send [connect_nbr]", true));
	return (EXIT_SUCCESS);
}
