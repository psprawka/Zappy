/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:09 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 23:03:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static t_commands g_commands[] =
  {
    {"advance", 7, command_advance},
    {"right", 7, command_right},
    {"left", 7, command_left},
    {"see", 7, command_see},
    {"inventory", 1, command_inventory},
    {"take", 7, command_take},
	{"put", 7, command_put},
	{"kick", 7, command_kick},
	{"broadcast", 7, command_broadcast},
	{"incantation", 300, command_levelup},
	{"fork", 42, command_fork},
	{"connect_nbr", 0, command_connect_nbr},
	{NULL, 0, NULL}
  };

int		delayComparison(t_event *first, t_event *second)
{
	//Return 0 on insertion. Insert earliest first.
	return (first->delaytime.tv_usec >= second->delaytime.tv_usec);
}

int		parse_recv(t_player *player, t_server *server, char *msg)
{
	int		i;
	t_event	event;

	i = 0;
	while (g_commands[i].msg)
	{
		if (!ft_strcmp(g_commands[i].msg, msg))
		{
			if (gettimeofday(&(event.delaytime), NULL) == EXIT_FAILURE)
			{
				//Set failure in X cycles? lol
				return (EXIT_FAILURE); //Idk what to do in this case tbh.
			}
			event.msg = ft_strdup(msg);
			event.player = player;
			event.delaytime.tv_usec += g_commands[i].delay * server->time.tv_usec;
			event.fct = g_commands[i].fct;
			printf("Function address = %p\n", g_commands[i].fct);
			ft_enpqueue(server->events, &event, sizeof(t_event), (int (*)(void *, void *))&delayComparison);
			return (EXIT_SUCCESS);
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
		ft_printf("message[%s]\n", buff);
		if (!player->team)
		{
			if (get_team_name(player, server, buff) == EXIT_FAILURE)
				player_quit(player, server);
		}
		else if (parse_recv(player, server, buff) == EXIT_SUCCESS)
			;
		else
			send(player->fd, MSG_NOCOMMAND, ft_strlen(MSG_NOCOMMAND), 0);
	}
	else
	{
		// player_quit(player, server);
		ret == 0 ? player_quit(player, server) : error(0, "Ret", false); //for debugging client
	}
	return (EXIT_SUCCESS);
}
