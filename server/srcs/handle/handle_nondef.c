/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nondef.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:03:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 03:53:23 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Function handle_nondef determines whether client is an ai (PLAYER)
**	or a gui (GRAPHIC). A client type (g_client_type[fd]) is set, its struct
**	is initialized and assigned to its fd in g_entity variable. A proper
**	'welcome' message is sent.
**	An EXIT_SUCCESS value is returned upon success, otherwise in case of
**	not fount message, function returns an EXIT_FAILURE value.
*/
int 	handle_nondef(int fd, char *msg)
{
	int		team_number;

	if (!ft_strcmp(msg, "GRAPHIC"))
	{
		if (g_server.graphic_fd)
			return (error(7, NULL, true));
		g_client_type[fd] = T_GRAPHIC;
		g_server.graphic_fd = fd;
		send_graphic_greeting(fd);
	}
	else if ((team_number = get_team_number(fd, msg)) != -1)
	{
		g_client_type[fd] = T_PLAYER;
		g_entity[fd] = init_player(fd);
		assign_team(fd, team_number);
		command_connect_nbr(g_entity[fd], NULL);
		tools_world_dimensions(g_entity[fd]);
		if (g_server.teams[team_number]->connected >= g_server.teams[team_number]->max_players)
		{
			if (g_server.teams[team_number]->allowed_eggs > 0)
			{
				g_server.teams[team_number]->allowed_eggs--;
				((t_player *)(g_entity[fd]))->x = ((t_egg *)(ft_top_queue(g_server.teams[team_number]->egg_queue)))->x;
				((t_player *)(g_entity[fd]))->y = ((t_egg *)(ft_top_queue(g_server.teams[team_number]->egg_queue)))->y;
				notify_connectegg(g_server.graphic_fd, ((t_egg *)(ft_top_queue(g_server.teams[team_number]->egg_queue))));
				notify_new_player(g_server.graphic_fd, ((t_player *)(g_entity[fd])));
			}
			if (send(fd, MSG_FULLTEAM, strlen(MSG_FULLTEAM), 0) == -1)
				error(0, "Send [handle_nondef]", true);
			return (-1);
		}
		notify_new_player(g_server.graphic_fd, g_entity[fd]);
		command_eat(g_entity[fd], NULL);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
