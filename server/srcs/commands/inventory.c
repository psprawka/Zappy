/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 19:16:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_inventory(t_player *player, t_server *serv)
{
	char buff[1024];
	
	ft_bzero(buff, 1024);
	ft_strcpy(buff, "{food");
	ft_strcat(buff, ft_itoa(player->inv->food * 126));
	ft_strcat(buff, ", linemate ");
	ft_strcat(buff, ft_itoa(player->inv->linemate));
	ft_strcat(buff, ", deraumere ");
	ft_strcat(buff, ft_itoa(player->inv->deraumere));
	ft_strcat(buff, ", mendiane ");
	ft_strcat(buff, ft_itoa(player->inv->mendiane));
	ft_strcat(buff, ", phiras ");
	ft_strcat(buff, ft_itoa(player->inv->phiras));
	ft_strcat(buff, ", thystame ");
	ft_strcat(buff, ft_itoa(player->inv->thystame));
	ft_strcat(buff, "}");
	send(player->fd, buff, ft_strlen(buff) + 1, 0);
	return (EXIT_SUCCESS);
}
