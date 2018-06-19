/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:33 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 03:54:56 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	ressource_drop(int fd, t_player *player, uint8_t ressource)
{
	int		len;

	strcpy(g_server.buff, "pdr ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(ressource));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: pdr]", true);
}
