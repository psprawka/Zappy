/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:36 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 11:02:43 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


// char	*message_see(t_player *player, t_server *serv, int squere, int leftsq)
// {
	// char	*msg;
	// if (leftsq == 0)
	// 	return (NULL);
	// msg = msg_get_inventory(serv, squere);
	// msg = ft_strjoin(msg, " ", 0);
	// return (ft_strjoin(msg, message_see(player, serv, next_squere(player, serv, squere), leftsq - 1)))
// }

char	*g_ressources[8] = {
	"food",
	"linemate",
	"deraumere",
	"sibur",
	"mendiane",
	"phiras",
	"thystame",
	NULL
};

int			calcul_far_right(int level)
{
	return (level * level + 2 * level);
}

int			nbr_player_square(t_square *square)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (i < FD_SETSIZE)
	{
		if (square->players[i])
			nbr++;
		i++;
	}
	return (nbr);
}

void		process_square(int x, int y, t_server *server)
{
	int				len;
	int				i;
	int				k;
	int				first;
	t_square		*square;

	len = 0;
	i = 0;
	first = 0;
	square = server->map->squares[x][y];
	while (i < nbr_player_square(square))
	{
		if (!first)
		{
			strcat(server->buff, " ");
			first = 1;
		}
		strcat(server->buff, "player");
		i++;
	}
	i = 0;
	while (i < 7)
	{
		k = 0;
		while (k < square->ressources[k])
		{
			if (!first)
			{
				strcat(server->buff, " ");
				first = 1;
			}
			strcat(server->buff, g_ressources[i]);
			k++;
		}
		i++;
	}
}

int			command_see(t_player *player, t_server *server, t_action_arg *arg)
{
	int		y;
	int		column;

	y = 0;
	strcat(server->buff, "{");
	while (y <= player->level)
	{
		column = -y;
		while (column < y)
		{
			process_square(column, y, server);
			strcat(server->buff, ", ");
			column++;
		}
		y++;
	}
	strcat(server->buff, "}\n");
	send(player->fd, server->buff, strlen(server->buff) + 1, 0);

	//test
	// send(player->fd, "seeing\n", 7, 0);
	return (EXIT_SUCCESS);
}
