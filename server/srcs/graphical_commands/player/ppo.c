/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:16 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:34:45 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	player_position(int fd, t_player *player)
{
	int				len;
	char			*freer;

	strcpy(g_server.buff, "ppo ");
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
	strcat(g_server.buff, "\n");
	len = ft_strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) == -1)
		printf("Error send ppo\n");
}
