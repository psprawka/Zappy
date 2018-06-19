/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:16 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 04:24:58 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_new_player(int fd, t_player *player)
{
	int				len;

	strcpy(g_server.buff, "pnw ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->x));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->y));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(graphic_direction(player->direction)));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->level));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, player->team->name);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: pnw]", true);
}
