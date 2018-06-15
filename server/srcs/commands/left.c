/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 13:11:02 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_left(void *object, t_action_arg *arg)
{
	t_player	*player;


	player = (t_player *)object;
	printf("Player %d has sent command [left]\n", player->fd);
	player->direction = (player->direction / 2 == 0) ? WEST : player->direction / 2;
	if (send(player->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
		return (error(0, "Send", false));
	arg = (void *)arg;
	return (EXIT_SUCCESS);
}

//i think this one is fine too
