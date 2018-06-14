/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:54:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 11:05:32 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_fork(t_player *player, t_server *serv, t_action_arg *arg)
{
	printf("Player %d has sent command [fork]\n", player->fd);

	//for test
	if (send(player->fd, "forking!\n", 9, 0) == -1)
		return (error(0, "Send", false));
	arg = (void *)arg;
	return (EXIT_SUCCESS);
}

//not done at all
