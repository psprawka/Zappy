/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teams.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:57:59 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 02:24:58 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int	get_team_name(t_player *player, t_server *serv, char *msg)
{
	int		i;
	
	i = 0;
	ft_printf("[%s]\n", msg);
	while (serv->teams && serv->teams[i])
	{
		if (!ft_strncmp(serv->teams[i]->name, msg, ft_strlen(msg)))
		{
			// send(player->fd, MSG_FULLTEAM, ft_strlen(MSG_FULLTEAM), 0);
			// ft_printf("Team name: [%s], players left: [%d]\n", serv->teams[i]->name, 6 - serv->teams[i]->players);
			if (serv->teams[i]->players == 6)
				send(player->fd, MSG_FULLTEAM, ft_strlen(MSG_FULLTEAM), 0);
			player->team = serv->teams[i];
			command_connect_nbr(player, serv);
			tools_world_dimensions(player, serv);
			player->team->players += 1;
		}
		i++;
	}
	if (!player->team)
		send(player->fd, MSG_NOTEAM, ft_strlen(MSG_NOTEAM), 0);
	return (EXIT_SUCCESS);
}

