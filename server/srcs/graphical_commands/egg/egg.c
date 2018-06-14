/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:05:15 by asyed             #+#    #+#             */
/*   Updated: 2018/06/13 17:50:38 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_layegg(t_player *player, t_server *server)
{
	int				len;
	t_graphic_list	*node;

	strcpy(server->buff, "pfk #");
	strcat(server->buff, ft_itoa(player->fd));
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

void	notify_hatchegg(t_player *player, t_server *server)
{
	int		len;
	t_graphic_list	*node;

	strcpy(server->buff, "eht #");
	strcat(server->buff, ft_itoa(player->fd));
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

void	notify_connectegg(t_player *player, t_server *server)
{
	int		len;
	t_graphic_list	*node;

	strcpy(server->buff, "eht #");
	strcat(server->buff, ft_itoa(player->fd));
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
