/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:45:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/29 21:44:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)ft_strnew(sizeof(t_map));
	map->x = 10;
	map->y = 10;
	map->map = NULL;
	return (map);
}

t_inv		*init_inv(void)
{
	t_inv	*inventory;

	inventory = (t_inv *)ft_strnew(sizeof(t_inv));

	inventory->linemate = 0;
	inventory->deraumere = 0;
	inventory->sibur = 0;
	inventory->mendiane = 0;
	inventory->phiras = 0;
	inventory->thystame = 0;
	inventory->food = 0;
	return (inventory);
}

t_player	*init_player(int sockfd)
{
	t_player *new;

	new = (t_player *)ft_strnew(sizeof(t_player));
	new->fd = sockfd;
	new->team = NULL;
	new->level = 0;
	new->direction = rand_direction();
	new->inv = init_inv();
	new->see_range = 1;
	new->position = rand_position();
	new->lifetime = 1260;
	return (new);
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