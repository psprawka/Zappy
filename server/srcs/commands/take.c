/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:59 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 21:36:59 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_take(t_player *player, t_server *serv, int ressource)
{
	t_square	*square;
	int			x;
	int			y;

	ft_printf("taking!\n");
	if (ressource < 0 || ressource > 6)
	{
		printf("Error ressource number\n");
		return (EXIT_FAILURE);
	}
	x = player->x;
	y = player->y;
	square = serv->map->squares[x][y];
	if (square->ressource > 0)
	{
		player->inv->ressource++;
		square->ressource--;
		if (send(player->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
			return (error(0, "Send", false));
	}
	else
	{
		if (send(player->fd, MSG_KO, strlen(MSG_OK), 0) == -1)
			return (error(0, "Send", false));
	}
	return (EXIT_SUCCESS);
}
