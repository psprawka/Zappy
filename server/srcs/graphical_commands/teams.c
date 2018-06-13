/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teams.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:55:24 by asyed             #+#    #+#             */
/*   Updated: 2018/06/12 23:31:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	send_teams(t_graphic *client, t_server *server)
{
	int			i;
	int			len;
	t_node		*node;

	i = 0;
	while (server->teams && server->teams[i])
	{
		ft_strcpy(server->buff, "tna ");
		ft_strcat(server->buff, server->teams[i]->name);
		ft_strcat(server->buff, "\n");
		len = ft_strlen(server->buff) + 1;
		if (!(node = server->graphics->first))
			return ;
		while (node)
		{
			send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
			node = node->next;
		}
		i++;
	}
}

void	notify_new_player(t_player *player, t_server *server)
{
	t_node	*node;
	int		len;

	if (!(node = server->graphics->first))
		return ;
	ft_strcpy(server->buff, "pnw ");
	ft_strcat(server->buff, "#");
	ft_strcat(server->buff, ft_itoa(player->fd));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->position->x));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->position->y));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->direction));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->level));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, player->team->name);
	ft_strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	while (node)
	{
		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
		node = node->next;
	}
}

void	player_level(t_player *player, t_server *server)
{
	t_node	*node;
	int		len;

	if (!(node = server->graphics->first))
		return ;
	ft_strcpy(server->buff, "plv #");
	ft_strcat(server->buff, ft_itoa(player->fd));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(player->level));
	ft_strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	while (node)
	{
		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
		node = node->next;
	}
