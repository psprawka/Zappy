/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teams.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:57:59 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 10:48:15 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

struct timeval	*lifetime()
{
	return (NULL);
}

int		get_team_name(t_player *player, t_server *serv, char *msg)
{
	int		i;

	i = 0;
	if (if_graphical(serv, player, msg) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	while (serv->teams && serv->teams[i])
	{
		if (!ft_strncmp(serv->teams[i]->name, msg, ft_strlen(msg)))
		{
			if (serv->teams[i]->connected == serv->teams[i]->max_players)
			{
				send(player->fd, MSG_FULLTEAM, ft_strlen(MSG_FULLTEAM), 0);
				return (EXIT_FAILURE);
			}
			player->team = serv->teams[i];
			if (command_connect_nbr(player, serv, 0) == EXIT_FAILURE || 
				tools_world_dimensions(player, serv) == EXIT_FAILURE)
				return (EXIT_FAILURE); //idk what to do in this situation?
			player->team->connected += 1;
			ft_printf("[%d]dsjhjdasjhads\n", player->team->connected);
			player->type = T_PLAYER;
			// push_pdeath(&serv->deaths, player, lifetime());
			return (EXIT_SUCCESS);
		}
		i++;
	}
	if (!player->team)
		send(player->fd, MSG_NOTEAM, ft_strlen(MSG_NOTEAM), 0);
	return (EXIT_SUCCESS);
}
