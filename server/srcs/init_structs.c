/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:45:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/04 15:46:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_square	**init_squares(t_server *server)
{
	int			i;
	int			j;
	t_square	**new;

	if (!(new = ft_memalloc(server->map->width * sizeof(t_square *))))
		return (NULL);
	i = 0;
	while (i < server->map->width)
	{
		if (!(new[i] = ft_memalloc(server->map->height * sizeof(t_square))))
		{
			//Free all that aren't NULL.
			return (NULL);
		}
		j = 0;
		while (j < server->map->height)
		{
			new[i][j].x = i;
			new[i][j].y = j;
			j++;
		}
		i++;
	}
	return (new);
}

int			init_map(t_server *server)
{
	if (!(server->map->squares = init_squares(server)))
		return (EXIT_FAILURE);
	return (0);
}

t_player	*init_player(int sockfd, t_server *server)
{
	t_player *new;

	if (!(new = ft_memalloc(sizeof(t_player))))
		return (NULL);
	new->fd = sockfd;
	new->direction = rand_direction();
	new->see_range = 1;
	if (!(new->position = rand_position(server->map)))
	{
		ft_printf("This should never actually be a case.... rand failed!? :O \"%s\"", strerror(errno));
		free(new);
		return (NULL);
	}
	new->lifetime = 1260;
	return (new);
}

int			init_server(t_server *server)
{
	if (!(server->players = ft_memalloc(sizeof(t_player *) * FD_SETSIZE)))
		return (EXIT_FAILURE);
	if (!(server->map = ft_memalloc(sizeof(t_map))))
	{
		free(server->players);
		return (EXIT_FAILURE);
	}
	if (!(server->events = init_pqueue()))
	{
		free(server->map);
		free(server->players);
		return (EXIT_FAILURE);
	}
	// server->time = 10;
	server->min_players = 1;
	return (EXIT_SUCCESS);
}
