/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:55:24 by asyed             #+#    #+#             */
/*   Updated: 2018/06/14 15:08:59 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		if_graphical(t_server *server, t_player *player, char *msg)
{
	if (player->type == T_NONDEF && strcmp(msg, "GRAPHIC\n"))
		return (EXIT_FAILURE);

	if (player->type == T_NONDEF)
	{
		//TODO: SEND FIRST COMMMAND

		send_mapcontents(player, g_server);
		//send welcome message to this player
		//add him to queue
		player->type = T_GRAPHICAL;
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
