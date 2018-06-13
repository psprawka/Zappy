/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:22 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 18:59:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int	command_death(t_player *player, t_server *server)
{
	if (!player->team)
		return (EXIT_FAILURE);

	player->team->players--;
	
	if (send(player->fd, MSG_DEATH, ft_strlen(MSG_DEATH), 0) == -1)
		return (error(0, "Send", false));
		
	return (EXIT_SUCCESS);
}
