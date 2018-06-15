/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:29:03 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:35:44 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		start_incantation(t_player *player, t_server *server)
{
	int		len;
	t_graphic_list	*node;

	strcpy(server->buff, "pgt #");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	// strcat(server->buff, ft_itoa(resource));
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
