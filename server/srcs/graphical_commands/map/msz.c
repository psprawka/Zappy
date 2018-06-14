/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:53:35 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		map_size(t_server *server)
{
	t_graphic_list		*node;
	int					len;

	strcpy(server->buff, "msz ");
	strcat(server->buff, ft_itoa(server->map->width));
	strcpy(server->buff, " ");
	strcat(server->buff, ft_itoa(server->map->height));
	strcpy(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	while (node)
	{
		send(node->fd, server->buff, len, 0);
		node = node->next;
	}
}
