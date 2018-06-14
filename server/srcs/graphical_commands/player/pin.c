/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:02 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:41:09 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	send_inventory(t_player *player, t_server *server)
{
	int		len;
	t_graphic_list	*node;

	strcpy(server->buff, "pin #");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->position->x));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->position->y));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->inv.food));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->inv.linemate));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->inv.deraumere));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->inv.sibur));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->inv.mendiane));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->inv.phiras));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->inv.thystame));
	strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	if (!(node = server->graph_list))
		return ;
	while (node)
	{
		send(node->fd, server->buff, len, 0);
		node = node->next;
	}
}
