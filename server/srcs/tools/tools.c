/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:23:45 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 10:58:52 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		tools_world_dimensions(t_player *player, t_server *serv)
{
	ft_bzero(serv->buff, SERV_BUFF_SIZE);
	ft_strcpy(serv->buff, ft_itoa(serv->map->width));
	ft_strcat(serv->buff, " ");
	ft_strcat(serv->buff, ft_itoa(serv->map->height));
	ft_strcat(serv->buff, "\n");

	if (send(player->fd, serv->buff, ft_strlen(serv->buff), 0) == -1)
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

int		hash_function(char *ressource)
{
	if (!strcmp(ressource, "food"))
		return (0);
	else if (!strcmp(ressource, "linemate"))
		return (1);
	else if (!strcmp(ressource, "deraumere"))
		return (2);
	else if (!strcmp(ressource, "sibur"))
		return (3);
	else if (!strcmp(ressource, "mendiane"))
		return (4);
	else if (!strcmp(ressource, "phiras"))
		return (5);
	else if (!strcmp(ressource, "thystame"))
		return (6);
	else
		return (-1);
}
