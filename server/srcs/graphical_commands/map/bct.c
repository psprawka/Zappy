/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:00:56 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/14 15:00:28 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	send_block_contents(int x, int y, t_player *gclient, t_server *server)
{
	int		len;
	t_graphic_list	*node;

	strcpy(server->buff, "bct ");
	strcat(server->buff, ft_itoa(x));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(y));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(server->map->squares[x][y].food));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(server->map->squares[x][y].linemate));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(server->map->squares[x][y].deraumere));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(server->map->squares[x][y].sibur));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(server->map->squares[x][y].mendiane));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(server->map->squares[x][y].phiras));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(server->map->squares[x][y].thystame));
	strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	if (!(node = server->graph_list))
		return ;
	if (gclient)
	{
		send(gclient->fd, server->buff, len, 0);
		return ;
	}
	while (node)
	{
		send(node->fd, server->buff, len, 0);
		node = node->next;
	}
}

void	send_mapcontents(t_player *player, t_server *server)
{
	int	i;
	int	j;

	i = 0;
	while (i < server->map->width)
	{
		j = 0;
		while (j < server->map->height)
		{
			send_block_contents(i, j, player, server);
			j++;
		}
		i++;
	}
}
