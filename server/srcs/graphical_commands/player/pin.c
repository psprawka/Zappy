/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:02 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 04:22:22 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


/*
**	resources[7]:
**	0 food;
**	1 linemate;
**	2 deraumere;
**	3 sibur;
**	4 mendiane;
**	5 phiras;
**	6 thystame;
*/

void	send_inventory(int fd, t_player *player)
{
	int		len;
	int		i;

	i = 0;
	strcpy(g_server.buff, "pin ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->x));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(player->y));
	while (i < 7)
	{
		strcat(g_server.buff, " ");
		strcat(g_server.buff, ft_itoa(player->inventory[i]));
		i++;
	}
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: pin]", true);
}
