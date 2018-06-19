/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pie.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:34:18 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 03:55:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		end_incantation(int fd, t_player *player, int result)
{
	int				len;

	strcpy(g_server.buff, "pie ");
	strcat(g_server.buff, ft_itoa(player->x));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->y));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(result));
	strcat(g_server.buff, "\n");
	len = ft_strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: pie]", true);
}
