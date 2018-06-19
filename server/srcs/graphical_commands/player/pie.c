/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pie.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:34:18 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/16 17:42:38 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		end_incantation(int fd, t_player *player, int result)
{
	int				len;
	char			*freer;

	strcpy(g_server.buff, "pie ");
	strcat(g_server.buff, (freer = ft_itoa(player->x)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->y)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(result)));
	free(freer);
	strcat(g_server.buff, "\n");
	len = ft_strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
