
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:28:47 by asyed             #+#    #+#             */
/*   Updated: 2018/06/08 14:14:17 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	send_inventory(t_player *player, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "pin #");
	ft_strcat(server->buff, ft_itoa(player->fd));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->position->x));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->position->y));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->inv.food));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->inv.linemate));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->inv.deraumere));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->inv.sibur));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->inv.mendiane));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->inv.phiras));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->inv.thystame));
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

void	notify_kick(t_player *player, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "pex #");
	ft_strcat(server->buff, ft_itoa(player->fd));
	len = ft_strlen(server->buff) + 1;
	if (!(node = server->graphics->first))
		return ;
	while (node)
	{
		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
		node = node->next;
	}
}

/*
** Hook function - not callable unless you pass it msg!
** Haven't decided if msg should be a stack or heap string.
*/

void	notify_broadcast(t_player *player, char *msg, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "pbc #");
	ft_strcat(server->buff, ft_itoa(player->fd));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, msg);
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

void	notify_starve(t_player *player, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "pdi #");
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