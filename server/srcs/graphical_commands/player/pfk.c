/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:59 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:03:54 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_lay_egg(t_player *player)
{
	strcpy(g_server.buff, "pfk ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, "\n");
	if (notify_graphics(0) == EXIT_FAILURE)
		error(0, "Send [g: pfk]", true);
}
