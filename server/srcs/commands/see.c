/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:36 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 21:36:51 by tle-huu-         ###   ########.fr       */
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
	while (i < square->food)
	{
		if (!first)
		{
			strcat(server->buff, " ");
			first = 1;
		}
		strcat(server->buff, "food");
		i++;
	}
	i = 0;
	while (i < square->deraumere)
	{
		if (!first)
		{
			strcat(server->buff, " ");
			first = 1;
		}
		strcat(server->buff, "deraumere");
		i++;
	}
	i = 0;
	while (i < square->sibur)
	{
		if (!first)
		{
			strcat(server->buff, " ");
			first = 1;
		}
		strcat(server->buff, "sibur");
		i++;
	}
	i = 0;
	while (i < square->mendiane)
	{
		if (!first)
		{
			strcat(server->buff, " ");
			first = 1;
		}
		strcat(server->buff, "mendiane");
		i++;
	}
	i = 0;
	while (i < square->phiras)
	{
		if (!first)
		{
			strcat(server->buff, " ");
			first = 1;
		}
		strcat(server->buff, "phiras");
		i++;
	}
	i = 0;
	while (i < square->thystame)
	{
		if (!first)
		{
			strcat(server->buff, " ");
			first = 1;
		}
		strcat(server->buff, "thystame");
		i++;
	}
	return (EXIT_SUCCESS);
}

int			command_see(t_player *player, t_server *serv)
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
			process_square(column, y);
			strcat(server->buff, ", ")
			column++;
		}
		y++;
	}
	strcat(server->buff, "}\n");
	send(player->fd, serv->buff, strlen(serv->buff) + 1, 0);
	return (EXIT_SUCCESS);
}
