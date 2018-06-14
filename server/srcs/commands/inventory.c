/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 21:01:05 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_inventory(t_player *player, t_server *serv)
{

	strcpy(serv->buff, "{food ");
	// strcat(serv->buff, ft_itoa(player->inv->food * 126));
	strcat(serv->buff, ft_itoa(player->inv->food));
	strcat(serv->buff, ", linemate ");
	strcat(serv->buff, ft_itoa(player->inv->linemate));
	strcat(serv->buff, ", deraumere ");
	strcat(serv->buff, ft_itoa(player->inv->deraumere));
	strcat(serv->buff, ", mendiane ");
	strcat(serv->buff, ft_itoa(player->inv->mendiane));
	strcat(serv->buff, ", phiras ");
	strcat(serv->buff, ft_itoa(player->inv->phiras));
	strcat(serv->buff, ", thystame ");
	strcat(serv->buff, ft_itoa(player->inv->thystame));
	strcat(serv->buff, "}\n");
	send(player->fd, serv->buff, strlen(serv->buff) + 1, 0);
	return (EXIT_SUCCESS);
}

//i think this one is fine
