/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:23:45 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 16:47:17 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		tools_world_dimensions(t_player *player, t_server *serv)
{
	ft_bzero(serv->buff, SERV_BUFF_SIZE);
	ft_strcpy(serv->buff, ft_itoa(server->map->width));
	ft_strcat(serv->buff, " ");
	ft_strcat(serv->buff, ft_itoa(server->map->height));
	ft_strcat(serv->buff, "\n");
	
	if (send(player->fd, msg, ft_strlen(msg), 0) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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