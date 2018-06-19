/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:36 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 03:40:33 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static int		calcul_far_right(int level)
{
	return (level * level + 2 * level);
}

static int		nbr_player_square(int x, int y, int current_fd)
{
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	while (i < FD_SETSIZE)
	{
		if (i != current_fd && g_client_type[i] == T_PLAYER
			&& ((t_player *)g_entity[i])->x == x
			&& ((t_player *)g_entity[i])->y == y)
			nbr++;
		i++;
	}
	return (nbr);
}

static void		put_in_buffer(t_square *square, int x, int y, int current_fd)
{
	int		nbr_players;
	int		first;

	nbr_players = nbr_player_square(x, y, current_fd);
	first = 0;
	put_player_buffer(nbr_players, &first);
	put_ressources_buffer(square, nbr_players, first);
}

static void		process_square(int x, int y, t_player *player)
{
	t_square		*square;

	if (player->direction == EAST)
		rotation90(&x, &y);
	else if (player->direction == SOUTH)
		rotation180(&x, &y);
	else if (player->direction == WEST)
		rotation270(&x, &y);
	x = ft_modulo(player->x + x, g_server.map->width);
	y = ft_modulo(player->y + y, g_server.map->height);
	square = g_server.map->squares[x][y];
	put_in_buffer(square, x, y, player->fd);
}

int				command_see(void *entity, char *msg)
{
	int		y;
	int		x;
	int		far_right;

	y = 0;
	printf("%sPlayer %d -> [see]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	strcpy(g_server.buff, "{");
	while (y <= P_ENTITY->level)
	{
		x = -y;
		while (x <= y)
		{
			process_square(x, y, P_ENTITY);
			strcat(g_server.buff, ", ");
			x++;
		}
		y++;
	}
	strcat(g_server.buff, "}\n");
	P_ENTITY->requests_nb--;
	if (send(P_ENTITY->fd, g_server.buff, strlen(g_server.buff), 0) == -1)
		return (error(0, "Send [see]", false));
	return (EXIT_SUCCESS);
}
