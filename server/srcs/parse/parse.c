/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:24:12 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 04:23:52 by psprawka         ###   ########.fr       */
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

/*
**	Function validate_args check if all needed arguments were given in
**	command line and sets max number of players for all the teams based
**	on "-c" argument. Along success, it returnes EXIT_SUCCESS, otherwise
**	error message is sent and EXIT_FAILURE returned. 
*/ 
int		validate_args(void)
{
	int i;
	
	i = 0;
	if (!g_server.map->width || g_server.timeunit == -1 || !g_server.map->height ||
		!g_server.teams || !g_server.max_team_players || !g_server.port)
		return(error(1, NULL, true));
	
	while (i < g_server.teamcount)
		g_server.teams[i++]->max_players = g_server.max_team_players; 	
	return (EXIT_SUCCESS);
}

/*
**	A parse_args function goes through all given arguments and parses them.
**	For all arguments function checks if:
**	-> dash indicating a flag,
**	-> flag is valid.
**	If somthing goes wrong error message is sent and EXIT_FAILURE returned,
**	otherwise validate_args' value is returned.
*/ 
int		parse_args(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-q") && opt_print_queue(av, &i))
			continue ;
		if (av[i][0] != '-' || ft_strlen(av[i]) != 2 || !av[i + 1])
			return (error(1, NULL, true));
		j = -1;
		while (g_ops[++j].opt)
		{
			if (av[i][1] == g_ops[j].opt)
			{
				if (g_ops[j].fct(av, &i) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				break ;
			}
		}
		if (!g_ops[j].opt)
			return (error(1, NULL, true));
	}
	return (validate_args());
}

