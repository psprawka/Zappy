/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:24:12 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 07:21:57 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static t_opt g_ops[] =
{
	{'p', opt_port},
	{'x', opt_dimentions},
	{'y', opt_dimentions},
	{'n', opt_teams},
	{'c', opt_max_players},
	{'t', opt_time},
	{'\0', NULL}
};

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
		ft_printf("Number of clients authorized at the beginning of the game has to be grater than 5 and less than %d.\n", FD_SETSIZE);
	else 
		ft_printf("%s%s: %s%s\n", RED, msg, strerror(errno), NORMAL);	
	return (ifexit == true ? EXIT_FAILURE : EXIT_SUCCESS);
}

int		check_args(t_server *server)
{
	if (!server->map->width || !server->map->height || !server->teams ||
		!server->max_team_players || !server->port)
		return(error(1, NULL, true));
	return (EXIT_SUCCESS);
}

int		parse_args_serv(int ac, char **av, t_server *server)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		// ft_printf("got here [%s]\n", av[i]);
		if (av[i][0] != '-' || ft_strlen(av[i]) != 2 || !av[i + 1])
			return (error(1, NULL, true));
		j = -1;
		while (g_ops[++j].opt)
		{
			if (av[i][1] == g_ops[j].opt)
			{
				if (g_ops[j].fct(av, &i, server) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				break ;
			}
		}
		if (!g_ops[j].opt)
			return (error(1, NULL, true));
	}
	return (check_args(server) == EXIT_FAILURE ||
		init_map(server) == EXIT_FAILURE ? EXIT_FAILURE : EXIT_SUCCESS);
		return (1);
}

