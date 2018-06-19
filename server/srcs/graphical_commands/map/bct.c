/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:00:56 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/16 19:59:44 by tle-huu-         ###   ########.fr       */
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
	int		len;
	char	*freer;

	strcpy(g_server.buff, "bct ");
	strcat(g_server.buff, (freer = ft_itoa(x)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(y)));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(g_server.map->squares[x][y]->ressources[0])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(g_server.map->squares[x][y]->ressources[1])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(g_server.map->squares[x][y]->ressources[2])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(g_server.map->squares[x][y]->ressources[3])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(g_server.map->squares[x][y]->ressources[4])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(g_server.map->squares[x][y]->ressources[5])));
	free(freer);
	strcat(g_server.buff, " ");
	strcat(g_server.buff, (freer = ft_itoa(g_server.map->squares[x][y]->ressources[6])));
	free(freer);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) <= 0)
		printf("PROBLEM\n");
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
