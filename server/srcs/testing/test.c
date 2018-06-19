/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:44:35 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/17 19:49:23 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

//just testing to remove
void	print_map(t_server *server, int x, int y)
{
	int i = 0, j;

	ft_printf("\nMAP:%s\n\n  ", ORANGE);
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			ft_printf("[%d, %d, %s%d%s, %s%d%s, %s%d%s] ", i, j, GREEN, server->map->squares[i][j]->ressources[0], ORANGE,
																RED, server->map->squares[i][j]->ressources[1], ORANGE,
																BLUE, server->map->squares[i][j]->ressources[2], ORANGE);
			j++;
		}
		ft_printf("\n\n  ");
		i++;
	}
	ft_printf("\n%s", NORMAL);
}


//test
void	printqueue(void)
{
	t_node		*node = g_server.events->first;
	t_event		*event;
	int 	i;

	i = 1;
	while (node)
	{
		event = node->data;
		if (event)
			ft_printf("%s%d [%d][%s][%d][%d] requests: [%d]%s\n", PINK, i++, ((t_player *)event->entity)->fd, event->msg, event->event_time->tv_sec, event->event_time->tv_usec, ((t_player *)event->entity)->requests_nb, NORMAL);

		node = node->next;
	}
}
