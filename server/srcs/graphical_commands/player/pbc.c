/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:50 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:45:51 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
** Hook function - not callable unless you pass it msg!
** Haven't decided if msg should be a stack or heap string.
*/

void	notify_broadcast(int fd, t_player *player, char *msg)
{
	int		len;
	char	*freer;

	strcpy(g_server.buff, "pbc ");
	strcat(g_server.buff, (freer = ft_itoa(player->fd)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, msg + strlen("broadcast "));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
