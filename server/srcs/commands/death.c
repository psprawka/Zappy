/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:22 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 00:57:54 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_death(t_player *player, t_server *serv)
{
	if (player->team)
		player->team->players--;
	send(player->fd, MSG_DEATH, ft_strlen(MSG_DEATH), 0);
	return (0);
}
