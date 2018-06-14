/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pie.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:34:18 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:43:27 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		end_incantation(t_player *player, t_server *server,int result)
{
	int				len;
	t_graphic_list	*node;
	int				i;
	t_square		square;

	strcpy(server->buff, "pie #");
	strcat(server->buff, ft_itoa(player->x));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->y));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->level));
	i = 0;
	square = server->map->squares[x][y];
	while (square->players[i])
	{
		strcat(server->buff, " #");
		strcat(server->buff, ft_itoa(square->players[i]->fd));
		i++;
	}
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
