/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:03:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 04:41:31 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Client_death determines a type of client who's about to die and do assigned
**	actions, frees, removes form a set of active fds, closes its socket and
**	sets an entity[fd] to NULL.
*/
void	client_death(int clientfd)
{
	printf("Player [%d] quit\n", clientfd);
	if (g_client_type[clientfd] == T_PLAYER)
	{
		clean_queue(clientfd);
		notify_starve(g_entity[clientfd]);
		free_player(clientfd);
	}
	else if (g_client_type[clientfd] == T_GRAPHIC)
		remove_list(&g_server.graphics, clientfd);
	FD_CLR(clientfd, &g_server.client_fds);
	close(clientfd);
	g_client_type[clientfd] = T_NONDEF;
	g_entity[clientfd] = NULL;
}

/*
**	Function new_client accepts new client coming from server socket, its
**	fd is added to FD_SET client_fds set and wecome message is sent.
**	In case of unsuccessful accept() error message is displayed.
*/
void	new_client(void)
{
	int 					connfd;
	struct sockaddr_in		temp;
	socklen_t				socklen;

	socklen = sizeof(struct sockaddr_in);
	ft_bzero(&temp, sizeof(struct sockaddr_in));
	if ((connfd = accept(g_server.serverfd, (struct sockaddr *)&temp, &socklen)) == -1)
		error(0, "Accept [new_client]", false);
	else
	{
		printf("New client joined [%d]\n", connfd);
		FD_SET(connfd, &g_server.client_fds);
		send(connfd, MSG_WELCOME, strlen(MSG_WELCOME), 0);
	}
}
