/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 00:38:17 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_left(t_player *player, t_server *serv)
{
	ft_printf("%s -> ", (player->direction & WEST ? "WEST" : (player->direction & EAST ? "EAST" :
	(player->direction & SOUTH ? "SOUTH" : "NORTH"))));

	player->direction = (player->direction == 1) ? WEST : player->direction / 2;
	
	ft_printf("%s\n", (player->direction & WEST ? "WEST" : (player->direction & EAST ? "EAST" :
	(player->direction & SOUTH ? "SOUTH" : "NORTH"))));
	return (1);
}
