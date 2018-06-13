/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:45:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 15:49:36 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		init_square(t_square *square)
{
	int	i;

	i = 0;
	if (!(square = ft_memalloc(sizeof(t_square))))
		return (EXIT_FAILURE);
	square->linemate = 0;
	square->deraumere = 0;
	square->sibur = 0;
	square->mendiane = 0;
	square->phiras = 0;
	square->thystame = 0;
	square->food = 0;
	if (!(square->players = ft_memalloc(sizeof(t_player) * FD_SETSIZE)))
		return (EXIT_FAILURE);
	while (i < FD_SETSIZE)
		square->players[i++] = NULL;
	return (EXIT_SUCCESS);
}

int		init_map(t_server *server)
{
	int i;
	int j;

	i = 0;
	if (!(server->map->squares = ft_memalloc(server->map->height * sizeof(t_square *))))
		return (EXIT_FAILURE);
	while (i < server->map->height)
	{
		if (!(server->map->squares[i] = ft_memalloc(server->map->width * sizeof(t_square))))
		{
			//Free all that aren't NULL.
			return (EXIT_FAILURE);
		}
		j = 0;
		while (j < server->map->width)
		{
			if (init_square(server->map->squares[i][j++]) == EXIT_FAILURE)
				return(error(0, "Initialize map", true));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}


t_player	*init_player(int sockfd, t_server *server)
{
	t_player *new;

	if (!(new = ft_memalloc(sizeof(t_player))))
		return (NULL);
	new->fd = sockfd;
	new->team = NULL;
	new->level = 0;
	new->direction = rand_direction();
	if (!(new->inv = ft_memalloc(sizeof(t_inv))))
		error(0, "Initialize inventory", false);
	new->inv->food = 10;
	new->see_range = 1;
	rand_position(new, server->map);
	new->last_request.tv_sec = 0;
	new->last_request.tv_usec = 0;
	new->requests_nb = 0;
	new->type = T_NONDEF;
	return (new);
}

int			init_server(t_server *serv)
{
	if (!(serv->players = ft_memalloc(sizeof(t_player *) * FD_SETSIZE)))
		return (EXIT_FAILURE);
	if (!(serv->map = ft_memalloc(sizeof(t_map))))
	{
		free(serv->players);
		return (EXIT_FAILURE);
	}
	if (!(serv->buff = ft_memalloc(2048 * sizeof(char))))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
