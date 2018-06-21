/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:03:51 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_kick(t_player *player)
{
	strcpy(g_server.buff, "pex ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, "\n");
	if (notify_graphics(0) == EXIT_FAILURE)
		error(0, "Send [g: pex]", true);
}
