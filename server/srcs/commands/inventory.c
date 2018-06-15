/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 13:12:40 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_inventory(void *object, t_action_arg *arg)
{
	t_player	*player;

	player = (t_player *)object;
	printf("Player %d has sent command [inventory]\n", player->fd);
	strcpy(g_server->buff, "{food ");
	strcat(g_server->buff, ft_itoa(player->inventory[0]));
	strcat(g_server->buff, ", linemate ");
	strcat(g_server->buff, ft_itoa(player->inventory[1]));
	strcat(g_server->buff, ", deraumere ");
	strcat(g_server->buff, ft_itoa(player->inventory[2]));
	strcat(g_server->buff, ", sibur ");
	strcat(g_server->buff, ft_itoa(player->inventory[3]));
	strcat(g_server->buff, ", mendiane ");
	strcat(g_server->buff, ft_itoa(player->inventory[4]));
	strcat(g_server->buff, ", phiras ");
	strcat(g_server->buff, ft_itoa(player->inventory[5]));
	strcat(g_server->buff, ", thystame ");
	strcat(g_server->buff, ft_itoa(player->inventory[6]));
	strcat(g_server->buff, "}\n");
	send(player->fd, g_server->buff, strlen(g_server->buff) + 1, 0);
	arg = (void *)arg;
	return (EXIT_SUCCESS);
}

//i think this one is fine
