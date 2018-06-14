/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:43:35 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_kick(t_player *player, t_server *server)
{
	int		len;
	t_graphic_list	*node;

	strcpy(server->buff, "pex #");
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
