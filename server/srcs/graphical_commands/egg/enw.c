/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:57:44 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 04:23:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_egg_laid(int fd, t_player *player, t_egg *egg)
{
	int		len;

	strcpy(g_server.buff, "enw ");
	strcat(g_server.buff, ft_itoa(egg->number));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->x));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->y));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: enw]", true);
}
