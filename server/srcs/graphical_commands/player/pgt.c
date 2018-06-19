/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:02:38 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:34:27 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	ressource_pickup(int fd, t_player *player, int ressource)
{
	int		len;
	char	*freer;

	strcpy(g_server.buff, "pgt ");
	strcat(g_server.buff, (freer = ft_itoa(player->fd)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(ressource)));
	free(freer);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
