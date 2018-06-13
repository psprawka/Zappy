/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:06 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 15:50:14 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_connect_nbr(t_player *player, t_server *serv)
{
	ft_bzero(serv->buff, 2048);
	ft_strcpy(serv->buff, ft_itoa(player->team->max_players - player->team->connected));
	ft_strcat(serv->buff, "\n");
	if (send(player->fd, serv->buff, ft_strlen(serv->buff), 0) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//this one should be fine too
