/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:09:01 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 02:28:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Function opt_print_queue simply sets flag print_queue to true.
*/	
int		opt_print_queue(char **av, int *i)
{
	(*i)++;
	g_server.print_queue = true;
	return (EXIT_SUCCESS);
}

/*
**	First 3 functions listed below just take an argument, chnage it to a number
**	and assign to proper variable in server. When arguments don't make server's
**	requirements (port number etc.) error message is sent and EXIT_FAILURE value
**	is returned, otherwise function returns EXIT_SUCCESS.
*/
int 	opt_port(char **av, int *i)
{
	int port;

	port = ft_atoi(av[*i + 1]);
	if (port > 65535 || port < 1024)
		return (error(2, NULL, true));
	*i += 2;
	g_server.port = port;
	return (EXIT_SUCCESS);
}

int 	opt_dimentions(char **av, int *i)
{
	int number;

	number = ft_atoi(av[*i + 1]);
	if (number > 100 || number < 2)
		return (error(3, NULL, true));
	if (!ft_strncmp(av[*i], "-x", 2))
		g_server.map->width = number;
	else
		g_server.map->height = number;
	*i += 2;
	return (EXIT_SUCCESS);
}

int		opt_max_players(char **av, int *i)
{
	int players;

	players = ft_atoi(av[*i + 1]);
	if (players < 1 || players > FD_SETSIZE)
		return (error(5, NULL, true));
	*i += 2;
	g_server.max_team_players = players;
	return (EXIT_SUCCESS);
}

/*	Opt_time function checks if time unit is valid, then sets time
**	inside ret struct (second and microseconds) based on the time unit.
**	Time and timeunit in server are set and EXIT_SUCCESS is returned.
*/
int		opt_time(char **av, int *i)
{
	int 			time_unit;
	struct timeval	ret;

	time_unit = ft_atoi(av[*i + 1]);
	if (time_unit < 1 || time_unit > 10000)
		return (error(6, NULL, true));
	*i += 2;
	ret.tv_usec = ((double)1 / time_unit) * 1000000;
	ret.tv_usec %= 1000000;
	ret.tv_sec = (1 / time_unit);
	g_server.time = ret;
	g_server.timeunit = time_unit;
	return (EXIT_SUCCESS);
}


/*	Opt_teams function count total number of teams given in command line
**	and assigns it to server's teamcount variable. Then, space for all
**	teams is allocated (teams) and next each team's struct allocs separetly
**	(oneteam variable). Name is set and each oneteam is assigned to teams
**	based on teams_nb variable. EXIT_SUCCESS is returned upon succesfull
**	execution, otherwise error displayed and EXIT_FAILURE returned.
*/
int		opt_teams(char **av, int *i)
{
	int		teams_nb;
	int		j;

	(*i)++;
	j = *i;
	teams_nb = 0;
	while (av[*i] && av[*i][0] != '-' && (*i)++)
		teams_nb++;
	if (!teams_nb)
		return (error(4, NULL, true));
	g_server.teamcount = teams_nb;
	if (!(g_server.teams = ft_memalloc(sizeof(t_team) * (teams_nb + 1))))
		return (EXIT_FAILURE);
	while (j < *i)
	{
		if (!(g_server.teams[--teams_nb] = ft_memalloc(sizeof(t_team))))
			return (EXIT_FAILURE);
		g_server.teams[teams_nb]->egg_queue = ft_init_queue();
		g_server.teams[teams_nb]->name = av[j++];
	}
	return(EXIT_SUCCESS);
}
