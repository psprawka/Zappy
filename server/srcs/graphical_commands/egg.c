/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:05:15 by asyed             #+#    #+#             */
/*   Updated: 2018/06/12 23:30:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_layegg(t_player *player, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "pfk #");
	ft_strcat(server->buff, ft_itoa(player->fd));
	ft_strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	if (!(node = server->graphics->first))
		return ;
	while (node)
	{
		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
		node = node->next;
	}
}

void	notify_hatchegg(t_player *player, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "eht #");
	ft_strcat(server->buff, ft_itoa(player->fd));
	ft_strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	if (!(node = server->graphics->first))
		return ;
	while (node)
	{
		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
		node = node->next;
	}
}

void	notify_connectegg(t_player *player, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "eht #");
	ft_strcat(server->buff, ft_itoa(player->fd));
	ft_strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	if (!(node = server->graphics->first))
		return ;
	while (node)
	{
		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
		node = node->next;
	}
}