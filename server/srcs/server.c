/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:25:37 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 23:58:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	print_map(t_server *server, int x, int y)
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

	ft_printf("\nRESOURCES:%s\n", PINK);
	i = 0; j = 0;
	// while(server->map->squeres[i])
	
}


static int	new_player(t_server *server)
{
	int 			connfd;
	struct kevent	evSet;

	if ((connfd = accept(server->socket_fd, NULL, 0)) == -1)
		return (error(6, "Accept error", true));
	ft_printf("New player joined [%d]\n", connfd);
	if (!(server->players[connfd] = init_player(connfd, server)))
	{
		close(connfd);
		return (EXIT_FAILURE);
	}
	if (send(connfd, MSG_WELCOME, ft_strlen(MSG_WELCOME), 0) == -1)
		player_quit(server->players[connfd], server);
	EV_SET(&evSet, connfd, EVFILT_READ, EV_ADD | EV_EOF, 0, 0, NULL);
	if (kevent(server->kfd, &evSet, 1, NULL, 0, NULL) == -1)
	{
		player_quit(server->players[connfd], server);
		return (error(6, "kevent error", true));
	}
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

static int	init_kqueue(int server_fd, t_server *server)
{
	int 			kfd;
	struct kevent	evSet;

	if ((kfd = kqueue()) == -1)
		return (EXIT_FAILURE);
	server->socket_fd = server_fd;
	EV_SET(&evSet, server_fd, EVFILT_READ, EV_ADD | EV_EOF, 0, 0, NULL);
	if (kevent(kfd, &evSet, 1, NULL, 0, NULL) == -1 || evSet.flags & EV_ERROR)
	{
		printf("Error: \"%s\"\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	ft_bzero(&evSet, sizeof(struct kevent));
	EV_SET(&evSet, 1, EVFILT_TIMER, EV_ADD, NOTE_USECONDS, server->time.tv_usec, NULL);
	printf("%d microseconds\n", server->time.tv_usec);
	if (kevent(kfd, &evSet, 1, NULL, 0, NULL) == -1 || evSet.flags & EV_ERROR)
	{
		printf("Error: \"%s\"\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	server->kfd = kfd;
	return (EXIT_SUCCESS);
}

static int process_fd(struct kevent *event, t_server *server)
{
	if (event->flags & EV_EOF)
	{
		printf("Player quit!\n");
		player_quit(server->players[event->ident], server);
		return (EXIT_SUCCESS);
	}
	if (event->ident == server->socket_fd)
	{
		if (new_player(server) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (process_data(server->players[event->ident], server) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
** Upon quit remove the filter from the kqueue.
*/

int		runserver(int server_fd, t_server *server)
{
	int				i;
	int				ret;
	int				max;
	struct kevent	*events; //Pick a better number than 32.

	max = server->teamcount * 6;
	if (!(events = ft_memalloc(max * sizeof(struct kevent))))
		return (EXIT_FAILURE);
	if ((init_kqueue(server_fd, server)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while ((ret = kevent(server->kfd, NULL, 0, events, max, NULL)) > 0)
	{
		i = 0;
		while (i < ret)
		{
			if (i >= max)
			{
				printf("wtf? Error! \"%s\"\n", strerror(errno));
				exit(42);
			}
			if (events[i].filter & EVFILT_TIMER)
			{
				if (events[i].data > 1)
					// printf("Lagging, tick delayed %ld\n", events[i].data);
				//timer
				// printf("Timer elapsed! %ld times\n", events[i].data);
				check_queue(server);
			}
			else if (process_fd(&(events[i]), server) == EXIT_FAILURE) //Handle return value.
				return (EXIT_FAILURE);
			i++;
		}
	}
	printf("Error with kevent(event_handler) \"%s\"\n", strerror(errno));
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
	
	if (init_server(&server) == EXIT_FAILURE ||
		parse_args_serv(ac, av, &server) == EXIT_FAILURE || 
		(sockfd = server_socket(ft_atoi(av[2]))) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	print_map(server.map->width, server.map->height); // 
	
	if (listen(sockfd, FD_SETSIZE) == -1)
		return (error(0, "Listen", true));
	if (runserver(sockfd, &server) == EXIT_FAILURE)
	{
		printf("Error: \"%s\"\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}