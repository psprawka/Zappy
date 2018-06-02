/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:06 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 15:43:17 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_connect_nbr(t_player *player, t_server *serv)
{
	char *msg;

	if (!(msg = ft_itoa(6 - player->team->players)))
		return (EXIT_FAILURE);
	send(player->fd, msg, ft_strlen(msg), 0);
	free(msg);
	return (0);
}
