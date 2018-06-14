/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:04:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 22:35:03 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//something similar in broadcast

// void	process_data(t_player *player, int sockfd, fd_set *client_fds)
// {
// 	int		ret;
// 	char	buff[BUFF_SIZE];
// 	int 	i;

// 	if ((ret = recv(player->fd, buff, BUFF_SIZE, 0)) > 0)
// 	{
// 		i = 0;
// 		while (i < FD_SETSIZE)
// 		{
// 			if (FD_ISSET(i, client_fds))
// 			{
// 				if (i != sockfd)
// 				{
// 					if (send(i, buff, ret, 0) == -1)
// 							ft_printf("Sending unsuccessful\n");

// 				}
// 			}
// 			i++;
// 		}
// 		ft_bzero(buff, BUFF_SIZE);
// 	}
// 	}
// }
#include "zappy.h"


static int		mesage_from(t_map *map, t_player *sender, t_player *receiver)
{
	int				square;
	t_vector		translation;
	t_vector		center;
	t_vector		new_sender;
	t_vecor			new_receiver;
	t_vector		direction

	center.x = map->width / 2;
	center.y = map->height / 2;
	translation.x = center.x - receiver.x;
	translation.y = center.y - receiver.y;
	new_sender.x = sender.x + translation.x;
	new_sender.y = sender.y + translation.y;
	new_receiver.x = new_receiver.x + translation.x;
	new_receiver.y = new_receiver.y + translation.y;
	direction.x = new_sender->x - new_receiver->x;
	direction.y = new_sender->y - new_receiver->y;
	return (calcul_square(&direction))
}

void			send_message_to_others(t_player *sender, t_player *receiver, t_server *server, char *msg)
{
	int		i;
	int		square;

	i = 0;
	square = message_from(server->map, sender, receiver);
	strcpy(server->buff, "message ");
	strcat(server->buff, ft_itoa(square));
	strcat(server->buff, ",");
	strcat(server->buff, msg);
	if (msg[strlen(msg) - 1] != '\n')
		strcat(server->buff, "\n");
	while (i < FD_SETSIZE + 1)
	{
		// The server needs to keep in its structure the sockfd
		if (i != server->sockfd)
		{
			if (send(i, server->buff, strlen(server->buff) + 1, 0) == -1)
				printf("Sending unsuccessful\n");
		}
	}
}

int				command_broadcast(t_player *player, t_server *serv, char *message)
{
	int		i;

	printf("Player %s has sent command [broadcast] [%s]\n", player->fd, message);
	i = 0;
	while (i < FD_SETSIZE + 1)
	{
		if (serv->players[i])
			send_message_to_others(player, serv->players[i], server, message);
		i++;
	}
	if (send(player->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
		return (error(0, "Send", false));
	return (EXIT_SUCCESS);
}

//not done at all, some stuff on github
