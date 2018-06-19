/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 04:22:05 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_kick(int fd, t_player *player)
{
	int		len;

	strcpy(g_server.buff, "pex ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: pex]", true);
}
