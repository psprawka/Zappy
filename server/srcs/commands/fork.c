/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:54:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 21:39:27 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_fork(t_player *player, t_server *serv)
{
	printf("Player %s has sent command [fork]\n", player->fd);

	return (EXIT_SUCCESS);
}

//not done at all
