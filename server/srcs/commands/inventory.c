/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 15:50:53 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_inventory(t_player *player, t_server *serv)
{

	ft_strcpy(serv->buff, "{food");
	ft_strcat(serv->buff, ft_itoa(player->inv->food * 126));
	ft_strcat(serv->buff, ", linemate ");
	ft_strcat(serv->buff, ft_itoa(player->inv->linemate));
	ft_strcat(serv->buff, ", deraumere ");
	ft_strcat(serv->buff, ft_itoa(player->inv->deraumere));
	ft_strcat(serv->buff, ", mendiane ");
	ft_strcat(serv->buff, ft_itoa(player->inv->mendiane));
	ft_strcat(serv->buff, ", phiras ");
	ft_strcat(serv->buff, ft_itoa(player->inv->phiras));
	ft_strcat(serv->buff, ", thystame ");
	ft_strcat(serv->buff, ft_itoa(player->inv->thystame));
	ft_strcat(serv->buff, "}");
	send(player->fd, serv->buff, ft_strlen(serv->buff) + 1, 0);
	return (EXIT_SUCCESS);
}

//i think this one is fine
