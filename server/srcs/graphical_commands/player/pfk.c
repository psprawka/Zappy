/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:59 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:30:26 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


void		lay_egg(t_player *player, t_server *server)
{
	int			len;
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
