/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 21:18:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 16:47:54 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


__attribute__((constructor))void init(void)
{
	srand(time(NULL));
}

int		main(int ac, char **av)
{
	int						sockfd;
	fd_set					client_fds;
	t_server				server;

	g_server = &server;
	if (init_server(&server) == EXIT_FAILURE ||
		parse_args_serv(ac, av, &server) == EXIT_FAILURE ||
		(sockfd = server_socket(server.port)) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	print_map(&server, server.map->width, server.map->height);

	if (listen(sockfd, FD_SETSIZE) == -1)
		return (error(0, "Listen", true));
	ft_bzero(&client_fds, sizeof(fd_set));
	FD_SET(sockfd, &client_fds);
	server.sockfd = sockfd;

	return (runserver(client_fds, &server, sockfd));
}
