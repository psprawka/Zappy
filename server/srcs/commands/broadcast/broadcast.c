/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:04:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 05:32:16 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static int		terence_modulo(int square)
{
	if (square >= 9)
		square = (square % 9) + 1;
	return (square);
}

static int		square_orientation(t_player *receiver, int square)
{
	int		direction;

	direction = receiver->direction;
	if (!square)
		return (0);
	if (direction == WEST)
		square = terence_modulo(square + 6);
	else if (direction == EAST)
		square = terence_modulo(square + 2);
	else if (direction == SOUTH)
		square = terence_modulo(square + 4);
	return (square);
}

static int		message_from(t_map *map, t_player *sender, t_player *receiver)
{
	t_vector		translation;
	t_vector		center;
	t_vector		new_sender;
	t_vector		new_receiver;
	t_vector		direction;

	center.x = map->width / 2;
	center.y = map->height / 2;
	translation.x = (center.x - receiver->x) % map->width;
	translation.y = (center.y - receiver->y) % map->height;
	new_sender.x = (sender->x + translation.x) % map->width;
	new_sender.y = (sender->y + translation.y) % map->height;
	new_receiver.x = (receiver->x + translation.x) % map->width;
	new_receiver.y = (receiver->y + translation.y) % map->height;
	direction.x = (new_sender.x - new_receiver.x) % map->width;
	direction.y = (new_sender.y - new_receiver.y) % map->height;
	return (calcul_square(&direction));
}

static void		send_message_to_others(t_player *sender, t_player *receiver, char *msg)
{
	int		i;
	int		square;

	i = 0;
	square = message_from(g_server.map, sender, receiver);
	square = square_orientation(receiver, square);
	strcpy(g_server.buff, "message ");
	strcat(g_server.buff, ft_itoa(square));
	strcat(g_server.buff, ",");
	strcat(g_server.buff, msg);
	if (msg[strlen(msg) - 1] != '\n')
		strcat(g_server.buff, "\n");
	if (send(receiver->fd, g_server.buff, strlen(g_server.buff), 0) == -1)
		error(0, "Send [broadcast_message]", false);

}
int				command_broadcast(void *entity, char *msg)
{
	int		i;

	printf("%sPlayer [%d] -> [broadcast]: [%s]%s\n", CYAN, P_ENTITY->fd, msg, NORMAL);
	i = 0;
	msg += ft_strlen("broadcast ");
	while (i < FD_SETSIZE)
	{
		if (g_client_type[i] == T_PLAYER && i != P_ENTITY->fd)
			send_message_to_others(P_ENTITY, g_entity[i], msg);
		i++;
	}
	P_ENTITY->requests_nb--;
	if (send(P_ENTITY->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
		return (error(0, "Send [broadcast]", false));
	notify_broadcast(P_ENTITY, msg);
	return (EXIT_SUCCESS);
}
