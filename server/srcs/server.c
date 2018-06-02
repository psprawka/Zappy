/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:25:37 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 15:45:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


void	print_map(int x, int y)
{
	int i = 0, j = 0;

	ft_printf("\nMAP:%s\n", ORANGE);
	while (i < y)
	{
		while (j < x)
		{
			ft_printf("%d", j + (i * x) + 1);
			ft_printf("%s",  j + (i * x) + 1 < 10 ? "   " : (j + (i * x) + 1 < 100 ? "  " : " "));
			j++;
		}
		j = 0;
		ft_printf("\n");
		i++;
	}
	ft_printf("\n%s", NORMAL);
}


void	check_select_fds(t_server *server, fd_set *client_fds, int sockfd)
{
	int connfd;

	if ((connfd = accept(sockfd, NULL, 0)) == -1)
		return (error(6, "Accept error", true));
		// ft_printf("Accept error\n");
	ft_printf("New player joined [%d]\n", connfd);
	if (connfd >= server->max)
		server->max = connfd + 1;
	FD_SET(connfd, &(server->server_fds));
	if (!(server->players[connfd] = init_player(connfd, server)))
	{
		close(connfd);
		return (EXIT_FAILURE);
	}
	if (send(connfd, MSG_WELCOME, ft_strlen(MSG_WELCOME), 0) == -1)
		player_quit(server->players[connfd], server);
	printf("Sent a welcome message\n");
	return (EXIT_SUCCESS);
}

void	check_queue(t_server *server)
{
	struct timeval	curr;
	t_node			*tmp;
	void			*content;

	if (gettimeofday(&curr, NULL) == -1)
	{
		error(6, "gettimeofday() failed", false);
		return ;
	}
	if (server->events)
		tmp = server->events->first;
	while (tmp)
	{
		if (((t_event *)tmp->content)->delaytime.tv_usec >= curr.tv_usec)
		{
			tmp = tmp->next;
			if (!(content = ft_depqueue(server->events)))
				error(6, "Failed to ft_depqueue", false);
			((t_event *)content)->fct(((t_event *)content)->player, server);
			free(content);
		}
		break ;
	}
}

static int	process_select(fd_set *fds, int server_fd, t_server *server)
{
	int	i;

	i = 0;
	while (i < server->max)
	{
		if (FD_ISSET(i, fds))
		{
			if (i == server_fd)
			{
				if (new_player(server, server_fd) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				//
			}
			else
			{
				if (process_data(server->players[i], server) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int		runserver(int server_fd, t_server *server)
{
	int				ret;
	fd_set			fds;
	struct timeval	timeout;

	server->max = server_fd + 1;
	FD_SET(server_fd, &fds);
	FD_COPY(&fds, &(server->server_fds));
	while ((ret = select(server->max, &fds, NULL, NULL, NULL)) >= 0)
	{
		printf("Unblocked\n");
		if (ret && process_select(&fds, server_fd, server) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		check_queue(server);
		FD_COPY(&(server->server_fds), &fds);
	}
	return (EXIT_FAILURE);
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
	
	if (init_server(&server) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	parse_args_serv(ac, av, &server);
	
	print_map(server.map->width, server.map->height); //to remove eventually
	
	sockfd = server_socket(ft_atoi(av[2]));
	if (listen(sockfd, FD_SETSIZE) == -1)
		return (error(0, "Listen", true));
	// ft_bzero(&client_fds, sizeof(fd_set));
	// FD_SET(sockfd, &client_fds);
	// runserver(sockfd, &server, sockfd);
	return (runserver(sockfd, &server));
}