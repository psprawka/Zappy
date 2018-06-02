/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:23:45 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/01 23:52:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	tools_world_dimensions(t_player *player, t_server *server)
{
	char *msg;

	msg = ft_strjoin(ft_itoa(server->map->width), " ", 0);
	
	msg = ft_strjoin(msg, ft_itoa(server->map->height), 0);
	send (player->fd, msg, ft_strlen(msg), 0);
	free(msg);
}
