/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:00:56 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:14:09 by psprawka         ###   ########.fr       */
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

void	send_block_contents(int fd, int x, int y)
{
	strcpy(g_server.buff, "bct ");
	strcat(g_server.buff, ft_itoa(x));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(y));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(g_server.map->squares[x][y]->ressources[0]));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(g_server.map->squares[x][y]->ressources[1]));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(g_server.map->squares[x][y]->ressources[2]));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(g_server.map->squares[x][y]->ressources[3]));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(g_server.map->squares[x][y]->ressources[4]));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(g_server.map->squares[x][y]->ressources[5]));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(g_server.map->squares[x][y]->ressources[6]));
	strcat(g_server.buff, "\n");
	if (notify_graphics(fd) == EXIT_FAILURE)
		error(0, "Send [g: bct]", true);
}

void	send_mapcontents(int fd)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_server.map->width)
	{
		j = 0;
		while (j < g_server.map->height)
		{
			send_block_contents(fd, i, j);
			j++;
		}
		i++;
	}
}
