/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:33 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:03:48 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_ressource_drop(t_player *player, uint8_t ressource)
{
	strcpy(g_server.buff, "pdr ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(ressource));
	strcat(g_server.buff, "\n");
	if (notify_graphics(0) == EXIT_FAILURE)
		error(0, "Send [g: pdr]", true);
}
