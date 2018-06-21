/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:03:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 06:16:26 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

#define WIDTH g_server.map->width
#define HEIGHT g_server.map->height

static void	send_kick_message(t_player *player, int kicked_from, int facing)
{
	int		k;

	k = 1;
	while (facing != kicked_from)
	{
		k += 2;
		if (facing & WEST)
			facing = SOUTH;
		else if (facing & SOUTH)
			facing = EAST;
		else if (facing & EAST)
			facing = NORTH;
		else if (facing & NORTH)
			facing = WEST;
	}
	strcpy(g_server.buff, "moving ");
	strcat(g_server.buff, ft_itoa(k));
	strcpy(g_server.buff, "\n");
	if (send(player->fd, g_server.buff, strlen(g_server.buff), 0) == -1)
		error(0, "Send [kick_message]", false);
}

static void	kick_player(t_player *kicker, t_player *to_kick)
{
	if (kicker->direction & NORTH)
	{
		to_kick->y = ft_modulo(to_kick->y + 1, g_server.map->height);
		send_kick_message(to_kick, SOUTH, to_kick->direction);
	}
	else if (kicker->direction & EAST)
	{
		to_kick->x = ft_modulo(to_kick->x + 1, g_server.map->width);
		send_kick_message(to_kick, WEST, to_kick->direction);
	}
	else if (kicker->direction & SOUTH)
	{
		to_kick->y = ft_modulo(to_kick->y - 1, g_server.map->height);
		send_kick_message( to_kick, NORTH, to_kick->direction);
	}
	else if (kicker->direction & WEST)
	{
		to_kick->x = ft_modulo(to_kick->x - 1, g_server.map->width);
		send_kick_message(to_kick, EAST, to_kick->direction);
	}
}

int			command_kick(void *entity, char *msg)
{
	int	i;
	int	tmp;

	i = 0;
	printf("%sPlayer [%d] -> [kick]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	while (i < FD_SETSIZE)
	{
		if ((g_client_type[i] != T_PLAYER) && ++i)
			continue;
		if (((t_player *)g_entity[i])->x == P_ENTITY->x && ((t_player *)g_entity[i])->y == P_ENTITY->y
			&& ((t_player *)g_entity[i])->fd != P_ENTITY->fd)
			{
				kick_player(P_ENTITY, g_entity[i]);
				notify_player_position(0, g_entity[i]);
			}
		i++;
	}
	P_ENTITY->requests_nb--;
	if (send(P_ENTITY->fd, MSG_OK, sizeof(MSG_OK), 0) == -1)
		return(error(0, "Send [kick]", false));
	notify_kick(P_ENTITY);
	return (EXIT_SUCCESS);
}