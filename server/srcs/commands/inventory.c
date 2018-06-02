/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 15:43:48 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_inventory(t_player *player, t_server *serv)
{
	char *msg;

	msg = ft_strjoin("{food ", ft_itoa(player->inv.food * 126), 0);
	msg = ft_strjoin(msg, ", linemate ", 0);
	msg = ft_strjoin(msg, ft_itoa(player->inv.linemate), 0);
	msg = ft_strjoin(msg, ", deraumere ", 0);
	msg = ft_strjoin(msg, ft_itoa(player->inv.deraumere), 0);
	msg = ft_strjoin(msg, ", mendiane ", 0);
	msg = ft_strjoin(msg, ft_itoa(player->inv.mendiane), 0);
	msg = ft_strjoin(msg, ", deraumere ", 0);
	msg = ft_strjoin(", phiras ", ft_itoa(player->inv.phiras), 0);
	msg = ft_strjoin(msg, ", deraumere ", 0);
	msg = ft_strjoin(", thystame ", ft_itoa(player->inv.thystame), 0);
	msg = ft_strjoin(msg, ", deraumere ", 0);
	return (0);
}
