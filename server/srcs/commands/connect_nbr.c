/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:06 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 19:28:29 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_connect_nbr(t_player *player, t_server *serv)
{
	char *msg;

	if (!(msg = ft_strjoin(ft_itoa(6 - player->team->players), "\n", 0)) || 
		send(player->fd, msg, ft_strlen(msg), 0) == -1)	//fix based on allowed number of connections
		return (EXIT_FAILURE);
	free(msg);
	return (EXIT_SUCCESS);
}
