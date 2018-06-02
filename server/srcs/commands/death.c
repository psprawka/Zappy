/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:22 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 03:12:32 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	command_death(t_player *player, t_server *server)
{
	int	i;

	if (!player->team)
		return ;
	player->team->players--;
	player->team->hlvl = 0;
	i = 0;
	if (server->players[i])
	{
		if (server->players[i]->team &&
			server->players[i]->team == player->team)
		{
			if (server->players[i]->level > server->players[i]->team->hlvl)
				server->players[i]->team->hlvl = server->players[i]->level;
		}
		i++;
	}
	send(player->fd, MSG_DEATH, ft_strlen(MSG_DEATH), 0);
}
