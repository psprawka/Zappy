/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:59 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 03:55:01 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


void		lay_egg(int fd, t_player *player)
{
	int			len;

	strcpy(g_server.buff, "pfk ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: pfk]", true);
}
