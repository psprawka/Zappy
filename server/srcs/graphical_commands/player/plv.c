/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:08 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:34:40 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	player_level(int fd, t_player *player)
{
	int				len;
	char			*freer;

	strcpy(g_server.buff, "plv ");
	strcat(g_server.buff, (freer = ft_itoa(player->fd)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->level)));
	free(freer);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);

}
