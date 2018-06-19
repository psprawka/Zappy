/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 00:14:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 04:31:59 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Function init_server allocates and initializes all server's variables
**	based on server's logic. All variables and their usage are better explained
**	in zappy_server.h file in includes directory.
*/
int			init_server(void)
{
	if (!(g_server.map = ft_memalloc(sizeof(t_map))))
		return (EXIT_FAILURE);
	if (!(g_server.buff = ft_memalloc(4096 * sizeof(char))))
		return (EXIT_FAILURE);
	g_server.events = ft_init_queue();
	// g_server.graphics = ft_init_queue();
	g_server.timeunit = -1;
	return (EXIT_SUCCESS);
}

/*
**	Function init_server_socket creates TCP socket for server and binds it.
*/
int			init_server_socket(void)
{
	struct sockaddr_in	server_addr;

	if ((g_server.serverfd = socket(AF_INET, SOCK_STREAM, 6)) < 0)
		return (error(0, "Socket [init_server_socket]", true));
	ft_bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(g_server.port);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(g_server.serverfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1)
		return (error(0, "Bind [init_server_socket]", true));
	printf("Server created succesfully!\n");
	return (EXIT_SUCCESS);
}
