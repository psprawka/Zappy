/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:25:37 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/01 15:01:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	check_select_fds(t_server *server, fd_set *client_fds, int sockfd)
{
	int 					connfd;
	struct sockaddr_in		temp;
	socklen_t				socklen;

	ft_bzero(&temp, sizeof(struct sockaddr_in));
	socklen = sizeof(struct sockaddr_in);

	if ((connfd = accept(sockfd, (struct sockaddr *)&temp, &socklen)) == -1)
		ft_printf("Accept error\n");
	else
	{
		ft_printf("New player joined [%d]\n", connfd);
		FD_SET(connfd, client_fds);
		server->players[connfd] = init_player(connfd, server);
		send(connfd, MSG_WELCOME, ft_strlen(MSG_WELCOME), 0);
	}
}

void	runserver(fd_set client_fds, t_server *server, int sockfd)
{
	int		i;
	fd_set	select_fds;

	while (1)
	{
		i = 0;
		select_fds = client_fds;
		if (select(FD_SETSIZE, &select_fds, NULL, NULL, NULL) == -1)
			error(0, "Select", true);
		while (i < FD_SETSIZE)
		{
			if (FD_ISSET(i, &select_fds))
			{
				if (i == sockfd)
					check_select_fds(server, &client_fds, sockfd);
				else
					process_data(server->players[i], server, &client_fds);
			}
			i++;
		}
	}
}

int		server_socket(int port)
{
	int					opt;
	int					sockfd;
	struct protoent		*protocol;
	struct sockaddr_in	server_addr;
	
	opt = true;
	protocol = getprotobyname("TCP");
	if ((sockfd = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) < 0)
		error(0, "Socket", true);
	ft_bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1)
		error(0, "Bind", true);
	ft_printf("Binding successful!\n");
	return (sockfd);
}

int		main(int ac, char **av)
{
	int						sockfd;
	fd_set					client_fds;
	t_server				server;
	
	init_server(&server);
	parse_args_serv(ac, av, &server);
	sockfd = server_socket(ft_atoi(av[2]));
	if (listen(sockfd, FD_SETSIZE) == -1)
		error(0, "Listen", true);
	ft_bzero(&client_fds, sizeof(fd_set));
	FD_SET(sockfd, &client_fds);
	runserver(client_fds, &server, sockfd);
	return (0);
}