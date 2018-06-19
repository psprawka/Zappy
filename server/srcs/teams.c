/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teams.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:57:59 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 02:17:22 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Function get_team_number iterates through all the teams given in server
**	execution as "-n" parameter and searches for requested team. If team is
**	found, it checks if there is a space avaliable in the team (second if
**	statement). If there is a spot (either initial spot or form a hatched egg),
**	team number is returned, otherwise a FULLTEAM message is sent.
**	If requested team does not exist, a NOTEAM message is sent and function
**	returns EXIT_FAILURE value.
*/

/*
**	Function get_team_number iterates through all the teams given in server
**	execution as "-n" parameter and searches for requested team.
**	If requested team does not exist, a NOTEAM message is sent and function
**	returns EXIT_FAILURE value.
*/
int		get_team_number(int clientfd, char *msg)
{
	int		i;

	i = 0;
	while (g_server.teams && g_server.teams[i])
	{
		if (!ft_strncmp(g_server.teams[i]->name, msg, ft_strlen(msg)) &&
			ft_strlen(msg) == ft_strlen(g_server.teams[i]->name))
			return (i);
		i++;
	}
	send(clientfd, MSG_NOTEAM, ft_strlen(MSG_NOTEAM), 0);
	return (-1);
}

/*
**	In function below team is assigned to a player and number of players
**	conneced to this team is increased.
*/
void		assign_team(int	clientfd, int team_nb)
{
	((t_player *)g_entity[clientfd])->team = g_server.teams[team_nb];
	((t_player *)g_entity[clientfd])->team->connected += 1;
}
