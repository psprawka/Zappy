/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:03:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/01 15:59:29 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	player_quit(t_player *player, t_server *serv)
{
	ft_printf("Player [%d] quit\n", player->fd);
	command_death(player, serv);
}