/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:25:37 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 10:47:51 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

//I didnt test this one yet
int		execute_deaths(t_server *server)
{
	struct timeval	*death_time;
	struct timeval	curr;

	while (server->deaths)
	{
		ft_bzero(&curr, sizeof(struct timeval));
		if (gettimeofday(&(curr), NULL) == EXIT_FAILURE)
			return (error(0, "Gettimeofday", true));

		death_time = top_pdeath(server->deaths);
		if (time_compare(death_time, &curr))
			break ;

		command_death(server->deaths->player, server, 0);
		pop_pdeath(&server->deaths);
	}
	return (EXIT_SUCCESS);
}

// this one just execute events and pops events from priority queue
int		execute_events(t_server *server)
{
	struct timeval	*event_time;
	struct timeval	curr;

	while (server->events)
	{
		ft_bzero(&curr, sizeof(struct timeval));
		if (gettimeofday(&(curr), NULL) == EXIT_FAILURE)
			return (error(0, "Gettimeofday", true));

		event_time = top_pevent(server->events);
		if (time_compare(event_time, &curr))
			break ;

		server->events->fct(server->events->player, server, 0);
		free_pevent(pop_pevent(&server->events));
	}
	return (EXIT_SUCCESS);
}

// set_time sets time based on fitst node in pqueue, if nothing exists NULL
 struct timeval		*set_time_alarm(t_server *server)
{
	struct timeval	*nextevent;
	struct timeval	curr;

	if (!(nextevent = ft_memalloc(sizeof(struct timeval))))
		return (NULL);
	if (server->events && server->events->event_time)
		nextevent = ft_memdup(server->events->event_time, sizeof(struct timeval));
	nextevent->tv_sec += nextevent->tv_usec / 1000000;
	nextevent->tv_usec %= 1000000;
	if (gettimeofday(&curr, NULL) == EXIT_FAILURE)
		return (NULL);
	if ((nextevent->tv_sec - curr.tv_sec) < 0)
		return (NULL);
	if ((nextevent->tv_usec - curr.tv_usec) < 0)
	{
		if ((nextevent->tv_sec - (curr.tv_sec + 1)) < 0)
			return (NULL);
		nextevent->tv_sec -= (curr.tv_sec + 1);
		nextevent->tv_usec += (1000000 - curr.tv_usec);
	}
	else
	{
		nextevent->tv_usec -= curr.tv_usec;
		nextevent->tv_sec -= curr.tv_sec;
	}
	return (nextevent);
}

int		runserver(fd_set client_fds, t_server *server, int servfd)
{
	int				i;
	fd_set			select_fds;
	struct timeval	*alarm;

	select_fds = client_fds;

	alarm = NULL;
	while (select(FD_SETSIZE, &select_fds, NULL, NULL, alarm) > -1)
	{
		i = 0;
		while (i < FD_SETSIZE + 1)
		{
			if (FD_ISSET(i, &select_fds))
			{
				if (i == servfd)
					new_player(server, &client_fds, servfd);
				else
					process_data(server->players[i], server, &client_fds);
			}
			i++;
		}
		execute_events(server);
		// execute_deaths(server);
		alarm = set_time_alarm(server);
		select_fds = client_fds;
	}
	return (error(0, "Select", true));
}

int		server_socket(int port)
{
	int					servfd;
	struct sockaddr_in	server_addr;

	if ((servfd = socket(AF_INET, SOCK_STREAM, 6)) < 0)
		return (error(0, "Socket", true));
	ft_bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(servfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1)
		return (error(0, "Bind", true));
	ft_printf("Binding successful!\n");
	return (servfd);
}
