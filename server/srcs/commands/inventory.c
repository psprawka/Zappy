/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 00:14:18 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_inventory(t_player *player, t_server *serv)
{
	printf("Player %d has sent command [inventory]\n", player->fd);
	strcpy(serv->buff, "{food ");
	strcat(serv->buff, ft_itoa(player->inventory[0]));
	strcat(serv->buff, ", linemate ");
	strcat(serv->buff, ft_itoa(player->inventory[1]));
	strcat(serv->buff, ", deraumere ");
	strcat(serv->buff, ft_itoa(player->inventory[2]));
	strcat(serv->buff, ", sibur ");
	strcat(serv->buff, ft_itoa(player->inventory[3]));
	strcat(serv->buff, ", mendiane ");
	strcat(serv->buff, ft_itoa(player->inventory[4]));
	strcat(serv->buff, ", phiras ");
	strcat(serv->buff, ft_itoa(player->inventory[5]));
	strcat(serv->buff, ", thystame ");
	strcat(serv->buff, ft_itoa(player->inventory[6]));
	strcat(serv->buff, "}\n");
	send(player->fd, serv->buff, strlen(serv->buff) + 1, 0);
	return (EXIT_SUCCESS);
}

//i think this one is fine
