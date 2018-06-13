/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:36 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 06:36:41 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


// char	*message_see(t_player *player, t_server *serv, int squere, int leftsq)
// {
	// char	*msg;
	// if (leftsq == 0)
	// 	return (NULL);
	// msg = msg_get_inventory(serv, squere);
	// msg = ft_strjoin(msg, " ", 0);
	// return (ft_strjoin(msg, message_see(player, serv, next_squere(player, serv, squere), leftsq - 1)))
// }

int		command_see(t_player *player, t_server *serv)
{
	// char	*msg;
	return (EXIT_SUCCESS);

	// msg = message_see(player, serv, player->position, player->see_range);
	// send(player->fd, msg, ft_strlen(see), 0);
}
