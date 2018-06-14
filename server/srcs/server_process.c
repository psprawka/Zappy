/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:09 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 07:35:21 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_commands g_commands[] =
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

int 	parse_graphical_recv(t_player *player, t_server *server, char *msg)
{

	;
	return (EXIT_SUCCESS);
}

int		parse_recv(t_player *player, t_server *server, char *msg)
{
	int i;
	
	i = 0;
	if (player->type & T_GRAPHICAL)
		return (parse_graphical_recv(player, server, msg));
	while (g_commands[i].msg)
	{
		if (!ft_strcmp(g_commands[i].msg, msg))
		{
			add_pevent(server, player, i, msg);
			// ft_printf("%s[%d]PQUEUE: [%d][%d]%s\n", PINK, player->fd, 
			// 	server->events->event_time->tv_sec, server->events->event_time->tv_usec, NORMAL);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

int		process_data(t_player *player, t_server *serv, fd_set *client_fds)
{
	int		ret;
	char	buff[BUFF_SIZE];

	if ((ret = recv(player->fd, buff, BUFF_SIZE, 0)) > 0)
	{
		buff[ret] = '\0';
		ft_printf("%s[%d]: [%s]%s\n", GREEN, player->fd, buff, NORMAL);
		if (!player->team && ~(player->type & T_GRAPHICAL))
			get_team_name(player, serv, buff);
		else if (parse_recv(player, serv, buff) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		else send(player->fd, MSG_NOCOMMAND, ft_strlen(MSG_NOCOMMAND), 0);
	}
	else
	{
		ft_printf("%s[%d]: [%s]%s\n", GREEN, player->fd, buff, NORMAL);
		ret == 0 ? player_quit(player, serv) : error(0, "Ret", false);
		FD_CLR(player->fd, client_fds);
		close(player->fd);
	}
	return (EXIT_SUCCESS);
}