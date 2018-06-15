/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:03:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 16:50:27 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	player_quit(t_player *player, t_server *serv)
{
	ft_printf("Player [%d] quit\n", player->fd);
	command_death(player, NULL);
}

void	new_client(fd_set *client_fds, int sockfd)
{
	int 					connfd;
	struct sockaddr_in		temp;
	socklen_t				socklen;

	ft_bzero(&temp, sizeof(struct sockaddr_in));
	socklen = sizeof(struct sockaddr_in);

	if ((connfd = accept(sockfd, (struct sockaddr *)&temp, &socklen)) == -1)
		error(0, "Accept error", false);
	else
	{
		ft_printf("New player joined [%d]\n", connfd);
		FD_SET(connfd, client_fds);
		serv->players[connfd] = init_player(connfd, serv);
		send(connfd, MSG_WELCOME, ft_strlen(MSG_WELCOME), 0);
	}
}
