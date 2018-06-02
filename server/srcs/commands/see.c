/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:36 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/01 23:50:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_see(t_player *player, t_server *serv)
{
	char	*msg;
	
	msg = "no";
	send(player->fd, msg, ft_strlen(msg), 0);
	return (0);
}
