/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:21 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 01:24:03 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_starve(int fd, t_player *player)
{
	int		len;
	char	*freer;

	strcpy(g_server.buff, "pdi ");
	strcat(g_server.buff, (freer = ft_itoa(player->fd)));
	free(freer);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
