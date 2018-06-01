/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:09 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/31 16:41:31 by psprawka         ###   ########.fr       */
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
	return (0);
}

void	process_data(t_player *player, t_server *serv, fd_set *client_fds)
{
	int		ret;
	char	buff[BUFF_SIZE];
	int 	i;

	ft_bzero(buff, BUFF_SIZE);
	if ((ret = recv(player->fd, buff, BUFF_SIZE, 0)) > 0)
	{
		ft_printf("recv msg if [%s]\n", buff);
		if (!player->team)
			get_team_name(player, serv, buff);
		else if (parse_recv(player, serv, buff))
		{
			;
			// push_priority_queue(player, recv);
		}
		else send(player->fd, MSG_NOCOMMAND, ft_strlen(MSG_NOCOMMAND), 0);
	}
	else
	{
		ft_printf("recv msg else [%s]\n", buff);
		ret == 0 ? player_quit(player, serv) : error(0, "Ret", false);
		FD_CLR(player->fd, client_fds);
		close(player->fd);
	}
}