/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:02:38 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 04:22:11 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	ressource_pickup(int fd, t_player *player, int ressource)
{
	int		len;

	strcpy(g_server.buff, "pgt ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(ressource));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: pgt]", true);
}
