/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 03:37:21 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_inventory(void *entity, char *msg)
{
	printf("%sPlayer [%d] -> [inventory]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	ft_bzero(g_server.buff, SERV_BUFF_SIZE);
	strcpy(g_server.buff, "{food ");
	strcat(g_server.buff, ft_itoa(P_ENTITY->inventory[0]));
	strcat(g_server.buff, ", linemate ");
	strcat(g_server.buff, ft_itoa(P_ENTITY->inventory[1]));
	strcat(g_server.buff, ", deraumere ");
	strcat(g_server.buff, ft_itoa(P_ENTITY->inventory[2]));
	strcat(g_server.buff, ", sibur ");
	strcat(g_server.buff, ft_itoa(P_ENTITY->inventory[3]));
	strcat(g_server.buff, ", mendiane ");
	strcat(g_server.buff, ft_itoa(P_ENTITY->inventory[4]));
	strcat(g_server.buff, ", phiras ");
	strcat(g_server.buff, ft_itoa(P_ENTITY->inventory[5]));
	strcat(g_server.buff, ", thystame ");
	strcat(g_server.buff, ft_itoa(P_ENTITY->inventory[6]));
	strcat(g_server.buff, "}\n");
	P_ENTITY->requests_nb--;
	if (send(P_ENTITY->fd, g_server.buff, strlen(g_server.buff), 0) == -1)
		return (error(0, "Send [inventory]", false));;
	return (EXIT_SUCCESS);
}

