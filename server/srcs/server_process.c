/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:09 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 03:15:03 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static t_commands g_commands[] =
  {
    {"advance", command_advance},
    {"right", command_right},
    {"left", command_left},
    {"see", command_see},
    {"inventory", command_inventory},
    {"take", command_take},
	{"put", command_put},
	{"kick", command_kick},
	{"broadcast", command_broadcast},
	{"incantation", command_levelup},
	{"fork", command_fork},
	{"connect_nbr", command_connect_nbr}
  };

int		parse_recv(t_player *player, t_server *server, char *msg)
{
	int i;
	
	i = 0;
	while (i < sizeof(g_commands) / sizeof(*g_commands))
	{
		if (!ft_strcmp(g_commands[i].msg, msg))
		{
			g_commands[i].fct(player, server);
			return (1);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

int		process_data(t_player *player, t_server *server)
{
	int		ret;
	char	buff[BUFF_SIZE];

	if ((ret = recv(player->fd, buff, BUFF_SIZE, 0)) > 0)
	{
		buff[ret] = '\0';
		ft_printf("recv msg of [%s]\n", buff);
		if (!player->team)
		{
			if (get_team_name(player, server, buff) == EXIT_FAILURE)
				player_quit(player, server);
		}
		else if (parse_recv(player, server, buff))
		{
			;
			// push_priority_queue(player, recv);
		}
		else
			send(player->fd, MSG_NOCOMMAND, ft_strlen(MSG_NOCOMMAND), 0);
	}
	else
	{
		ft_printf("recv msg else [%s]\n", buff);
		player_quit(player, server);
		// ret == 0 ? player_quit(player, server) : error(0, "Ret", false);
	}
	return (EXIT_SUCCESS);
}
