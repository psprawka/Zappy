/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:09:01 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/29 21:44:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int 	opt_dimentions(char **av, int *i)
{
	int number;

	number = ft_atoi(av[*i + 1]);
	if (number > 100 || number < 2)
		error(3, NULL, true);
	*i += 2;
	return (number);
}

int		opt_min_players(char **av, int *i)
{
	int number;

	number = ft_atoi(av[*i + 1]);
	if (number < 1 || number > FD_SETSIZE)
		error(5, NULL, true);
	*i += 2;
	return (number);
}

int		opt_time(char **av, int *i)
{
	int number;

	number = ft_atoi(av[*i + 1]);
	if (number < 0 || number > 1000)
		error(5, NULL, true);
	*i += 2;
	return (1 / number);
}

t_team	**opt_teams(char **av, int *i)
{
	t_team	**teams;
	t_team	*oneteam;
	int		teams_nb;

	teams_nb = 0;
	(*i)++;
	while (av[*i] && av[*i][0] != '-' && (*i)++)
		teams_nb++;
	if (!teams_nb)
		error(4, NULL, true);
	teams = (t_team **)ft_strnew(sizeof(t_team) * (teams_nb + 1));
	while (teams_nb--)
	{
		oneteam = (t_team *)ft_strnew(sizeof(t_team));
		oneteam->name = av[teams_nb];
		oneteam->players = 0;
		oneteam->hlvl = 0;
		teams[teams_nb] = oneteam;
	}
	return(teams);
}