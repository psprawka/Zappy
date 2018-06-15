/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:33 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:28:10 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	resource_drop(t_player *player, uint8_t resource, t_server *server)
{
	int		len;
	t_graphic_list	*node;

	strcpy(server->buff, "pdr #");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(resource));
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
