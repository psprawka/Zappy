/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:57:44 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:02:44 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_egg_laid(t_player *player, t_egg *egg)
{
	strcpy(g_server.buff, "enw ");
	strcat(g_server.buff, ft_itoa(egg->number));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->x));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->y));
	strcat(g_server.buff, "\n");
	if (notify_graphics(0) == EXIT_FAILURE)
		error(0, "Send [g: enw]", true);
}
