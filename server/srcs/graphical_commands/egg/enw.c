/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:57:44 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 03:51:24 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_egg_laid(int fd, t_player *player, t_egg *egg)
{
	int		len;
	char	*freer;

	strcpy(g_server.buff, "enw ");
	strcat(g_server.buff, (freer = ft_itoa(egg->number)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->fd)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->x)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->y)));
	free(freer);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
