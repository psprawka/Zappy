/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:54:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 08:12:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_fork(t_player *player, t_server *serv)
{
	printf("Player %d has sent command [fork]\n", player->fd);
	
	//for test
	if (send(player->fd, "forking!\n", 9, 0) == -1)
		return (error(0, "Send", false));
		
	return (EXIT_SUCCESS);
}

//not done at all
