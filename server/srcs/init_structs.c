/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:45:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/26 19:01:46 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_server.h"

t_map	*init_map()
{
	t_map	*map;

	map = (t_map *)ft_strnew(sizeof(t_map));
	map->x = 10;
	map->y = 10;
	map->map = NULL;
	return (map);
}

void	init_server(t_server *serv)
{
	serv->players = (t_player **)ft_strnew(sizeof(t_player *) * FD_SETSIZE);
	serv->map = init_map();
	serv->teams = NULL;
	serv->time = 10;
	serv->min_players = 1;
	serv->players_nb = 0;
}
