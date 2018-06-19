/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:29:03 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 05:35:31 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		start_incantation(int fd, t_player *player)
{
	int			len;
	char		*freer;
	// t_square	*square;
	int			x;
	int			y;
	int			i;

	// square = g_server.map->squares[player->x][player->y];
	x = player->x;
	y = player->y;
	strcpy(g_server.buff, "pic ");
	strcat(g_server.buff, (freer = ft_itoa(player->x)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->y)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(player->level)));
	free(freer);
	strcat(g_server.buff, " ");
	i = 0;
	while (i < FD_SETSIZE)
	{
		if (g_client_type[i] == T_PLAYER
			&& ((t_player *)(g_entity[i]))->x == x
			&& ((t_player *)(g_entity[i]))->y == y)
		{
			// strcat(g_server.buff, "#");
			strcat(g_server.buff, (freer = ft_itoa(((t_player *)(g_entity[i]))->fd)));
			free(freer);
			strcat(g_server.buff, " ");
		}
		i++;
	}
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	// ft_printf("------------------------------------\n[%s]\n----------------------------------------\n", g_server.buff);
	if (send(fd, g_server.buff, len, 0) == -1)
		error(0, "Error graphic start incantaton\n", true);
}
