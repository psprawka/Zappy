/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:24:12 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 23:57:48 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

// static int g_ops[] =
// {
// 	{'x', opt_dimentions},
// 	{'y', opt_dimentions},
// 	{'n', opt_teams},
// 	{'c', opt_min_players},
// 	{'t', opt_time},
// 	{'\0', NULL}
// };

int		error(int errnb, char *msg, bool ifexit)
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
	return (ifexit == true ? EXIT_FAILURE : EXIT_SUCCESS);
}

int		check_args(t_server *server)
{
	// if (!server->map->width || !server->map->height || !server->teams ||
	// 	!server->min_players || !)
}


int	parse_args_serv(int ac, char **av, t_server *server)
{
	int		i;

	if (ac < 13)
		error(1, NULL, true);
	if (ft_strcmp("-p", av[1]) || ft_atoi(av[2]) > 65535 || ft_atoi(av[2]) < 1024)
		return (error(2, NULL, true));
	i = 3;
	while (i < ac)
	{
		if (av[i][0] != '-' || !av[i][1] || !av[i + 1])
			return (error(1, NULL, true));
		if (av[i][1] == 'x')
			server->map->width = opt_dimentions(av, &i);
		else if (av[i][1] == 'y')
			server->map->height = opt_dimentions(av, &i);
		else if (av[i][1] == 'n')
			server->teams = opt_teams(av, &i, server);
		else if (av[i][1] == 'c')
			server->min_players = opt_min_players(av, &i);
		else if (av[i][1] == 't')
			server->time = opt_time(av, &i);
		else return (error(1, NULL, true));
	}
	// return (check_args(server) == EXIT_FAILURE ||
	// 	init_map(server) == EXIT_FAILURE ? EXIT_FAILURE : EXIT_SUCCESS);
		return (1);
}

