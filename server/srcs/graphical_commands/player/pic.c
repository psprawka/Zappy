/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:29:03 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:04:04 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static void	start_incantation_buff(t_player *player)
{
	ft_bzero(g_server.buff, SERV_BUFF_SIZE);
	strcpy(g_server.buff, "pic ");
	strcat(g_server.buff, ft_itoa(player->x));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->y));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->level));
	strcat(g_server.buff, " ");
}

void	notify_start_incantation(t_player *player)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	x = player->x;
	y = player->y;
	start_incantation_buff(player);
	while (i < FD_SETSIZE)
	{
		if (g_client_type[i] == T_PLAYER && ((t_player *)(g_entity[i]))->x == x
			&& ((t_player *)(g_entity[i]))->y == y)
		{
			strcat(g_server.buff, ft_itoa(((t_player *)(g_entity[i]))->fd));
			strcat(g_server.buff, " ");
		}
		i++;
	}
	strcat(g_server.buff, "\n");
	if (notify_graphics(0) == EXIT_FAILURE)
		error(0, "Send [g: pic]", true);
}
