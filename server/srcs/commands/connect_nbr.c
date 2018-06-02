/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:06 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/01 23:39:04 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_connect_nbr(t_player *player, t_server *serv)
{
	char *msg;

	msg = ft_itoa(6 - player->team->players);
	send(player->fd, msg, ft_strlen(msg), 0);
	free(msg);
	return (0);
}
