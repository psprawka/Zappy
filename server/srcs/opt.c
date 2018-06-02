/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:09:01 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 16:08:02 by asyed            ###   ########.fr       */
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

struct timeval	opt_time(char **av, int *i)
{
	int 			number;
	struct timeval	ret;

	number = ft_atoi(av[*i + 1]);
	if (number < 0 || number > 1000)
		error(5, NULL, true);
	*i += 2;
	ret.tv_usec =  ((double)1 / number) * 1000000;
	ret.tv_sec = (1 / number);
	// printf("float = %d double = %d\n", sizeof(float), sizeof(double));
	return (ret);
}

t_team	**opt_teams(char **av, int *i, t_server *server)
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
		error(4, NULL, true);
	server->teamcount = teams_nb;
	if (!(teams = ft_memalloc(sizeof(t_team) * (teams_nb + 1))))
		return (NULL);
	while (j < *i)
	{
		if (!(oneteam = ft_memalloc(sizeof(t_team))))
			return (NULL);
		oneteam->name = av[j++];
		teams[--teams_nb] = oneteam;
	}
	return(teams);
}