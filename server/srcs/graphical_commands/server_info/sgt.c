/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:11:15 by asyed             #+#    #+#             */
/*   Updated: 2018/06/13 17:48:20 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		send_timeunit(t_player *player, t_server *server)
{
	static char	timeunit[12] =	"\0";
	t_graphic_list				*node;
	int							len;

	if (!timeunit[0])
		strcpy(timeunit, ft_itoa(server->timeunit));
	strcpy(server->buff, "sgt ");
	strcat(server->buff, timeunit);
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
