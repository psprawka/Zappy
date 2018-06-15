/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:54:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 13:31:57 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "zappy.h"

int		command_fork(void *object, t_action_arg *arg)
{
	t_egg				*egg;
	t_list				*list;
	t_player			*player;
	struct timeval		deathtime;

	printf("Player %d has sent command [fork]\n", player->fd);
	player = (t_player *)object;
	if (!(egg = new_egg(player->team, player->x, player->y)))
		return (EXIT_FAILURE);
	if (!(list = ft_lstnew(egg, sizeof(t_egg))))
		return (EXIT_FAILURE);
	enqueue(player->team->eggqueue, list);
	// add egg in death queue 600 + 126 = 726
		// push_peath(&(g_server->deaths), egg, deathime);
	// Add egg hatches "event"
		
	//for test
	if (send(player->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
		return (error(0, "Send", false));
	arg = (void *)arg;
	return (EXIT_SUCCESS);
}

//not done at all
