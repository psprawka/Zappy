/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teams.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:57:59 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/29 23:11:45 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	get_team_name(t_player *player, t_server *serv, char *msg)
{
	int		i;
	
	i = 0;
	// msg = ft_trim_whitespaces(msg);
	while (serv->teams[i])
	{
		if (!ft_strcmp(serv->teams[i]->name, msg))
		{
			player->team = serv->teams[i];
			player->team->players += 1;
		}
		i++;
	}
	if (!player->team)
		ft_printf("Team [%s] doesn't exist. Reenter your team name.\n");
}