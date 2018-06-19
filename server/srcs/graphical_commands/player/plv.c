/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:08 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 03:55:15 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	player_level(int fd, t_player *player)
{
	int				len;

	strcpy(g_server.buff, "plv ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->level));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: plv]", true);

}
