/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 00:36:46 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_right(t_player *player, t_server *serv)
{
	ft_printf("%s -> ", (player->direction & WEST ? "WEST" : (player->direction & EAST ? "EAST" :
	(player->direction & SOUTH ? "SOUTH" : "NORTH"))));
	
	player->direction = (player->direction == 8) ? NORTH : player->direction * 2;

	ft_printf("%s\n", (player->direction & WEST ? "WEST" : (player->direction & EAST ? "EAST" :
	(player->direction & SOUTH ? "SOUTH" : "NORTH"))));
	
	return (1);
}
