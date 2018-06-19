/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:16 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:33:55 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_new_player(int fd, t_player *player)
{
	int				len;
	char			*freer;

	strcpy(g_server.buff, "pnw ");
	// strcat(g_server.buff, "#");
	strcat(g_server.buff, (freer = ft_itoa(player->fd)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->x)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->y)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(graphic_direction(player->direction))));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->level)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, player->team->name);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
