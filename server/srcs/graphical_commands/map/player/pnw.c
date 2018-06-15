/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:16 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:43:50 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_new_player(t_player *player, t_server *server)
{
	t_graphic_list	*node;
	int				len;

	if (!(node = server->graph_list))
		return ;
	strcpy(server->buff, "pnw ");
	strcat(server->buff, "#");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->position->x));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->position->y));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->direction));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->level));
	strcat(server->buff, " ");
	strcat(server->buff, player->team->name);
	strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	while (node)
	{
		send(node->fd, server->buff, len, 0);
		node = node->next;
	}
}
