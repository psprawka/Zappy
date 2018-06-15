/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:09:01 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 08:47:09 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int 	opt_port(char **av, int *i, t_server *server)
{
	int port;

	port = ft_atoi(av[*i + 1]);
	if (port > 65535 || port < 1024)
		return (error(2, NULL, true));
	*i += 2;
	server->port = port;
	// ft_printf("port %d\n", port);
	return (EXIT_SUCCESS);
}

int 	opt_dimentions(char **av, int *i, t_server *server)
{
	int number;

	number = ft_atoi(av[*i + 1]);
	if (number > 100 || number < 2)
		return (error(3, NULL, true));
		// ft_printf(" %p\n", server->map);
	if (!ft_strncmp(av[*i], "-x", 2))
		server->map->width = number;
	else 
		server->map->height = number;
	*i += 2;
	// ft_printf("number %d\n", number);
	return (EXIT_SUCCESS);
}

int		opt_max_players(char **av, int *i, t_server *server)
{
	int players;

	players = ft_atoi(av[*i + 1]);
	if (players < 1 || players > FD_SETSIZE)
		return (error(5, NULL, true));
	*i += 2;
	server->max_team_players = players;
	return (EXIT_SUCCESS);
}

int		opt_time(char **av, int *i, t_server *server)
{
	int 			time_unit;
	struct timeval	ret;

	time_unit = ft_atoi(av[*i + 1]);
	if (time_unit < 1 || time_unit > 1000)
		return (error(5, NULL, true));
	*i += 2;
	ret.tv_usec = ((double)1 / time_unit) * 1000000;
	ret.tv_usec %= 1000000;
	ret.tv_sec = (1 / time_unit);
	// ft_printf("%sTIME: [%d][%d]%s\n\n", ORANGE, ret.tv_sec, ret.tv_usec, NORMAL);
	server->time = ret;
	server->timeunit = time_unit;
	return (EXIT_SUCCESS);
}

int		opt_teams(char **av, int *i, t_server *server)
{
	t_team	**teams;
	t_team	*oneteam;
	int		teams_nb;
	int		j;

	teams_nb = 0;
	(*i)++;
	j = *i;
	while (av[*i] && av[*i][0] != '-' && (*i)++)
		teams_nb++;
	if (!teams_nb)
		return (error(4, NULL, true));
	server->teamcount = teams_nb;
	if (!(teams = ft_memalloc(sizeof(t_team) * (teams_nb + 1))))
		return (EXIT_FAILURE);
	while (j < *i)
	{
		if (!(oneteam = ft_memalloc(sizeof(t_team))))
			return (EXIT_FAILURE);
		oneteam->name = av[j++];
		oneteam->connected = 0;
		teams[--teams_nb] = oneteam;
	}
	server->teams = teams;
	return(EXIT_SUCCESS);
}