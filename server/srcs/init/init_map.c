/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 00:04:41 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 08:18:06 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Function init_square is used by init_map function. It allocates one square,
**	allocates space for players, sets each of them to NULL and sets square's
**	resources to 0. Due an error, message is sent and EXIT_FAILURE is returned,
**	otherwise function returns EXIT_SUCCESS.
*/
int		init_square(t_square **square)
{
	int	i;

	i = 0;
	if (!((*square) = ft_memalloc(sizeof(t_square))) ||
		!((*square)->players = ft_memalloc(sizeof(t_player) * FD_SETSIZE)))
		return (error(0, "Memalloc [init_square]", true));
	while (i < FD_SETSIZE)
		(*square)->players[i++] = NULL;
	return (EXIT_SUCCESS);
}

/////////////////////////////////////////
static void		init_map_ressource(void)
{
	int		i;
	int		k;
	int		ressource;
	int		nbr_team;
	int		map_size;

	i = 0;
	k = 0;
	ressource = 0;
	map_size = g_server.map->width;
	nbr_team = sizeof(g_server.teams) / sizeof(t_team);
	while (k < 10)
	{
		i = 0;
		while (i < map_size)
		{
			ressource = 0;
			while (ressource < 7)
			{
				generate_ressource(ressource);
				ressource++;
			}
			i++;
		}
		k++;
	}
}

/*
**	Function init_map allocates space for all squeres on the map and at this
**	point i think this function is broken :////
*/

int		init_map(void)
{
	int i;
	int j;

	i = 0;
	if (!(g_server.map->squares = ft_memalloc(g_server.map->width * sizeof(t_square **))))
		return (EXIT_FAILURE);
	while (i < g_server.map->width)
	{
		if (!(g_server.map->squares[i] = ft_memalloc(g_server.map->height * sizeof(t_square *))))
		{
			//Free all that aren't NULL.
			return (EXIT_FAILURE);
		}
		j = 0;
		while (j < g_server.map->height)
		{
			if (init_square(&(g_server.map->squares[i][j++])) == EXIT_FAILURE)
				return(error(0, "Initialize map", true));
		}
		i++;
	}
	init_map_ressource();
	return (EXIT_SUCCESS);
}
