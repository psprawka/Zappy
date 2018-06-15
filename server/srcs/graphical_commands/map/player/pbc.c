/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:50 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:41:15 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
** Hook function - not callable unless you pass it msg!
** Haven't decided if msg should be a stack or heap string.
*/

void	notify_broadcast(t_player *player, char *msg, t_server *server)
{
	int		len;
	t_graphic_list	*node;

	strcpy(server->buff, "pbc #");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	strcat(server->buff, msg);
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
