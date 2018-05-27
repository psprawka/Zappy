/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:24:12 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/26 19:07:22 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_server.h"

void	error(int errnb, char *msg, bool ifexit)
{
	if (errnb == 1)
		ft_printf("Usage: server -p <port> -x <width> -y <height> -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
	else if (errnb == 2)
		ft_printf("Port number has to be between 1024 and 65535!\n");
	else if (errnb == 3)
		ft_printf("x and y have to be between 2 and 100\n");
	else if (errnb == 4)
		ft_printf("At least one team required\n");
	else if (errnb == 5)
		ft_printf("Number of clients authorized at the beginning of the game has to be between 1 and %d\n", FD_SETSIZE);
	else 
		ft_printf("%s%s: %s%s\n", RED, msg, strerror(errno), NORMAL);	
	if (ifexit == true)
		exit(1);
}

void	parse_args_serv(int ac, char **av, t_server *serv)
{
	int		i;

	if (ac < 13)
		error(1, NULL, true);
	if (ft_strcmp("-p", av[1]) || ft_atoi(av[2]) > 65535 || ft_atoi(av[2]) < 1024)
		error(2, NULL, true);
	i = 3;
	while (i < ac)
	{
		if (av[i][0] != '-' || !av[i][1] || !av[i + 1])
			error(1, NULL, true);
		if (av[i][1] == 'x')
			serv->map->x = opt_dimentions(av, &i);
		else if (av[i][1] == 'y')
			serv->map->y = opt_dimentions(av, &i);
		else if (av[i][1] == 'n')
			serv->teams = opt_teams(av, &i);
		else if (av[i][1] == 'c')
			serv->min_players = opt_min_players(av, &i);
		else if (av[i][1] == 't')
			serv->time = opt_time(av, &i);
		else error(1, NULL, true);
	}
}

