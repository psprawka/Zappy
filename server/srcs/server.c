/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:25:37 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 16:15:22 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

// int		runserver(fd_set client_fds, t_server *server, int sockfd)
// {
// 	int						i;
// 	fd_set					select_fds;
// 	static struct timeval	alarm;

// 	select_fds = client_fds;

// 	// if (gettimeofday(&(alarm), NULL) == EXIT_FAILURE)
// 	// 		return (error(0, "Gettimeofday", true));
// 	alarm.tv_sec = 100;
// 	while (select(FD_SETSIZE, &select_fds, NULL, NULL, &alarm) > -1)
// 	{
// 		i = 0;
// 		while (i < FD_SETSIZE + 1)
// 		{
// 			if (FD_ISSET(i, &select_fds))
// 			{
// 				if (i == sockfd)
// 					new_player(server, &client_fds, sockfd);
// 				else
// 					process_data(server->players[i], server, &client_fds);
// 			}
// 			i++;
// 		}
// 		select_fds = client_fds;
// 		alarm.tv_sec = 100;
// 		if (server->events)
// 		{
// 			if (gettimeofday(&(alarm), NULL) == EXIT_FAILURE)
// 				return (error(0, "Gettimeofday", true));
// 			if (server->events->delaytime.tv_sec - alarm.tv_sec >= 0)
// 			{
// 				alarm.tv_sec = server->events->delaytime.tv_sec - alarm.tv_sec;
// 				alarm.tv_usec = server->events->delaytime.tv_usec - alarm.tv_usec;
// 			}
// 			else alarm.tv_sec = 100;
// 		}
// 		ft_printf("[%d][%d]", alarm.tv_sec, alarm.tv_usec);
// 		sleep(10);
// 	}
// 	return (error(0, "Select", true));
// }

int		runserver(fd_set client_fds, t_server *server, int sockfd)
{
	int						i;
	fd_set					select_fds;

	select_fds = client_fds;
	while (select(FD_SETSIZE, &select_fds, NULL, NULL, NULL) > -1)
	{
		i = 0;
		while (i < FD_SETSIZE + 1)
		{
			if (FD_ISSET(i, &select_fds))
			{
				if (i == sockfd)
					new_player(server, &client_fds, sockfd);
				else
					process_data(server->players[i], server, &client_fds);
			}
			i++;
		}
		select_fds = client_fds;
	}
	return (error(0, "Select", true));
}


int		server_socket(int port)
{
	int					sockfd;
	struct sockaddr_in	server_addr;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 6)) < 0)
		return (error(0, "Socket", true));
	ft_bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1)
		return (error(0, "Bind", true));
	ft_printf("Binding successful!\n");
	return (sockfd);
}
