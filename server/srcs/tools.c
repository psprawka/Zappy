/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:23:45 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 20:39:48 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	tools_world_dimensions(t_player *player, t_server *server)
{
	char	*msg;

	if (!(msg = ft_strjoin(ft_itoa(server->map->width), " ", 0)))
		return ;
	if (!(msg = ft_strjoin(msg, ft_itoa(server->map->height), 0)))
		return ;
	if (!(msg = ft_strjoin(msg, "\n", 0)))
		return ;
	send(player->fd, msg, ft_strlen(msg), 0);
	free(msg);
}

//just testing

void	print_map(t_server *server, int x, int y)
{
	int i = 0, j;

	ft_printf("\nMAP:%s\n\n  ", ORANGE);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("[%d, %d] ", i, j);
			j++;
		}
		ft_printf("\n\n  ");
		i++;
	}
	ft_printf("\n%s", NORMAL);

	// ft_printf("\nRESOURCES:%s\n", PINK);
	// i = 0; j = 0;
	// while(server->map->squeres[i])
}