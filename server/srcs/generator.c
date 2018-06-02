/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 01:46:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 04:24:53 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	generate_food(t_map *map, t_server *server)
{
	int	squere_nb;

	map->max_food = width * height / 3 * server->players_nb;

	while (map->current_food++ < map->max_food)
	{
		squere_nb = rand() % map->width * map->height + 1;
		map->squeres[squere_nb]->food++;
	}
}

void	add_stones_1(t_map *map)
{
	int	squere_nb;

	while (map->current_linemate++ < map->linemate)
	{
		squere_nb = rand() % map->width * map->height + 1;
		map->squeres[squere_nb]->linemate++;
	}
	while (map->current_deraumere++ < map->max_deraumere)
	{
		squere_nb = rand() % map->width * map->height + 1;
		map->squeres[squere_nb]->deraumere++;
	}
	while (map->current_sibur++ < map->max_sibur)
	{
		squere_nb = rand() % map->width * map->height + 1;
		map->squeres[squere_nb]->sibur++;
	}
}

void	add_stones_2(t_map *map)
{
	int	squere_nb;

	while (map->current_mendiane++ < map->mendiane)
	{
		squere_nb = rand() % map->width * map->height + 1;
		map->squeres[squere_nb]->mendiane++;
	}
	while (map->current_phiras++ < map->phiras)
	{
		squere_nb = rand() % map->width * map->height + 1;
		map->squeres[squere_nb]->phiras++;
	}
	while (map->current_thystame++ < map->max_thystame)
	{
		squere_nb = rand() % map->width * map->height + 1;
		map->squeres[squere_nb]->thystame++;
	}
}

void	generate_stones(t_map *map, t_server *server)
{
	max_linemate = width * height / 5 * server->players_nb;
	max_deraumere = width * height / 8 * server->players_nb;
	max_sibur = width * height / 7 * server->players_nb;
	max_mendiane = width * height / 10 * server->players_nb;
	max_phiras =  width * height / 7 * server->players_nb;
	max_thystame = width * height / 13 * server->players_nb;

	add_stones_1(map);
	add_stones_2(map);
}


