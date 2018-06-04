/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:57:53 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/04 16:13:03 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

__attribute__((constructor)) int	init(void)
{
	srand(time(NULL));
	return (EXIT_SUCCESS);
}	

int		main(int ac, char **av)
{
	int						sockfd;
	fd_set					client_fds;
	t_server				server;
	
	if (init_server(&server) == EXIT_FAILURE ||
		parse_args_serv(ac, av, &server) == EXIT_FAILURE || 
		(sockfd = server_socket(server.port)) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	print_map(&server, server.map->width, server.map->height);
	if (listen(sockfd, FD_SETSIZE) == -1)
		return (error(0, "Listen", true));
	if (runserver(sockfd, &server) == EXIT_FAILURE)
	{
		printf("Error: \"%s\"\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}