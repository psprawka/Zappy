/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:33 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:34:20 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	ressource_drop(int fd, t_player *player, uint8_t ressource)
{
	int		len;
	char	*freer;

	strcpy(g_server.buff, "pdr ");
	strcat(g_server.buff, (freer = ft_itoa(player->fd)));
	strcat(g_server.buff, " ");
	free(freer);
	strcat(g_server.buff, (freer = ft_itoa(ressource)));
	strcat(g_server.buff, "\n");
	free(freer);
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
