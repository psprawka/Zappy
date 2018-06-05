/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:04:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/01 23:39:07 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

enum e_shape		detect_shape(__attribute__((unused)) t_server *server)
{
	return (rectangle);
}

static t_square	**copy_squares(const t_map *map)
{
	int			i;
	int			j;
	t_square	**new;

	if (!map->squares || !map->squares[0])
		return (NULL);
	if (!(new = ft_memalloc(map->width * sizeof(t_square *))))
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		if (!(new[i] = ft_memalloc(map->height * sizeof(t_square))))
		{
			//ToDo: Free all already allocated ones.
			return (NULL);
		}
		j = 0;
		while (j < map->height)
		{
			ft_memcpy(&(new[i][j]), &(map->squares[i][j]), sizeof(t_square));
			j++;
		}
		i++;
	}
	return (new);
}

static t_map		*top_left(t_player *player, t_server *server)
{
	t_map	*translated;

	if (!(translated = ft_memalloc(sizeof(t_map))))
		return (NULL);
	ft_memcpy(translated, server->map, sizeof(t_map));
	if (!(translated->squares = copy_squares(server->map)))
		return (NULL);
	return (translated);
}

static t_map		**translate_maps(t_player *player, t_server *server)
{
	t_map	**translations;

	if (!(translations = ft_memalloc(5 * sizeof(t_map *))))
		return (NULL);
	if (!(translations[0] = top_left(player, server)))
	{
		free(translations);
		return (NULL);
	}
	return (translations);
}

int					broadcast_rectangle(t_player *player, t_server *server)
{
	int			i;
	t_map		**translations;
	t_player	*receiver;

	if (!(translations = translate_maps(player, server)))
		return (EXIT_FAILURE);
	i = 0;
	while (server->players[i])
	{
		receiver = server->players[i];

		i++;
	}
	return (EXIT_SUCCESS);
}

/*
** ToDo:
** Change this to be a pointer to a function and then have it choose
** upon creating the map if its going to be a rectangle or a square that
** way we take it out of the processing pipeline! :)
**
** Is there a way to make it so that we don't need to create 4 copies of the
** whole map?
*/

int					command_broadcast(t_player *player, t_server *server)
{
	static enum e_shape	shape = none;

	ft_printf("broadcast!\n");
	if (!shape)
		shape = detect_shape(server);
	if (shape == rectangle)
		return (broadcast_rectangle(player, server));
	ft_printf("Don't know the shape!\n");
	return (EXIT_FAILURE);
}