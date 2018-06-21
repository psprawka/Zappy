/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:08 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:04:28 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_player_level(int fd, t_player *player)
{
	strcpy(g_server.buff, "plv ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->level));
	strcat(g_server.buff, "\n");
	if (notify_graphics(fd) == EXIT_FAILURE)
		error(0, "Send [g: plv]", true);

}
