/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:25:37 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 20:58:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


// int		runserver(fd_set client_fds, t_server *server, int servfd)
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
// 				if (i == servfd)
// 					new_player(server, &client_fds, servfd);
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

/*
	t_commands g_commands[] =
	{
		{"advance", 7, command_advance},
		{"right", 7, command_right},
		{"left", 7, command_left},
		{"see", 7, command_see},
		{"inventory", 1, command_inventory},
		{"take", 7, command_take},
		{"put", 7, command_put},
		{"kick", 7, command_kick},
		{"broadcast", 7, command_broadcast},
		{"incantation", 300, command_levelup},
		{"fork", 42, command_fork},
		{"connect_nbr", 0, command_connect_nbr},
		{NULL, 0, NULL}
	};
*/

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

		command_death(server->deaths->player, server);
		pop_pdeath(&server->deaths);
	}
	return (EXIT_SUCCESS);
}


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

		server->events->fct(server->events->player, server);
		free_pevent(pop_pevent(&server->events));
	}
	return (EXIT_SUCCESS);
}


int		runserver(fd_set client_fds, t_server *server, int servfd)
{
	int			i;
	fd_set		select_fds;

	select_fds = client_fds;
	while (select(FD_SETSIZE, &select_fds, NULL, NULL, NULL) > -1)
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
		// execute_events(server);
		// execute_deaths(server);
		// set_time_alarm();
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
