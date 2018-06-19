/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:21 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 03:54:52 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_starve(int fd, t_player *player)
{
	int		len;

	strcpy(g_server.buff, "pdi ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: pdi]", true);
}
