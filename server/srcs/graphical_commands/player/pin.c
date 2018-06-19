/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:02 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:34:35 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


/*
**	resources[7]:
**	0 food;
**	1 linemate;
**	2 deraumere;
**	3 sibur;
**	4 mendiane;
**	5 phiras;
**	6 thystame;
*/

void	send_inventory(int fd, t_player *player)
{
	int		len;
	char	*freer;

	strcpy(g_server.buff, "pin ");
	strcat(g_server.buff, (freer = ft_itoa(player->fd)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->x)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->y)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->inventory[0])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->inventory[1])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->inventory[2])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->inventory[3])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->inventory[4])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->inventory[5])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->inventory[6])));
	free(freer);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);

}
