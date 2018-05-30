/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:09 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/29 23:13:03 by psprawka         ###   ########.fr       */
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

int		parse_recv(char *msg)
{
	return (0);
}

void	process_data(t_player *player, t_server *serv, fd_set *client_fds)
{
	int		ret;
	char	buff[BUFF_SIZE];
	int 	i;

	if ((ret = recv(player->fd, buff, BUFF_SIZE, 0)) > 0)
	{
		if (!player->team)
			get_team_name(player, serv, buff);
		else if (parse_recv(buff))
		{
			;
			// push_priority_queue(player, recv);
		}
		else ft_printf("Command [%s] doesn't exist!", buff);
	}
	else
	{
		ret == 0 ? ft_printf("Player [%d] quit\n", player->fd) : ft_printf("Error recv\n");
		FD_CLR(player->fd, client_fds);
		close(player->fd);
	}
}