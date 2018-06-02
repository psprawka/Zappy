/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:45:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 04:37:45 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)ft_strnew(sizeof(t_map));
	map->width = 10;
	map->height = 10;
	map->map = NULL;
	max_food = 0;
	max_linemate = 0;
	max_deraumere = 0;
	max_sibur = 0;
	max_mendiane = 0;
	max_phiras = 0;
	max_thystame = 0;
	current_food = 0;
	current_linemate = 0;
	current_deraumere = 0;
	current_sibur = 0;
	current_mendiane = 0;
	current_phiras = 0;
	current_thystame = 0;
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

t_player	*init_player(int sockfd, t_server *server)
{
	t_player *new;

	new = (t_player *)ft_strnew(sizeof(t_player));
	new->fd = sockfd;
	new->team = NULL;
	new->level = 0;
	new->direction = rand_direction();
	new->inv = init_inv();
	new->see_range = 1;
	new->position = rand_position(server->map);
	new->lifetime = 1260;
	new->requests = 0;
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