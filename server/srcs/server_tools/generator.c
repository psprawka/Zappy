/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 01:46:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 03:22:12 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		generate_ressource(int ressource)
{
	int		x;
	int		y;

	if (ressource < 0 || ressource > 6)
	{
		printf("Coder, you are retarded (generate ressource)\n");
		return ;
	}
	x = rand() % g_server.map->width;
	y = rand() % g_server.map->height;
	((g_server.map->squares[x][y])->ressources[ressource])++;
}

void		init_map_ressource(void)
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


// void	add_stones_1(t_map *map)
// {
// 	int	squere_nb;

// 	while (map->current_linemate++ < map->linemate)
// 	{
// 		squere_nb = rand() % map->width * map->height + 1;
// 		map->squeres[squere_nb]->linemate++;
// 		printf("squere [%d] line\n", squere_nb);
// 	}
// 	while (map->current_deraumere++ < map->max_deraumere)
// 	{
// 		squere_nb = rand() % map->width * map->height + 1;
// 		map->squeres[squere_nb]->deraumere++;
// 		printf("squere [%d] dera\n", squere_nb);
// 	}
// 	while (map->current_sibur++ < map->max_sibur)
// 	{
// 		squere_nb = rand() % map->width * map->height + 1;
// 		map->squeres[squere_nb]->sibur++;
// 		printf("squere [%d] sibur\n", squere_nb);
// 	}
// }

// void	add_stones_2(t_map *map)
// {
// 	int	squere_nb;

// 	while (map->current_mendiane++ < map->mendiane)
// 	{
// 		squere_nb = rand() % map->width * map->height + 1;
// 		map->squeres[squere_nb]->mendiane++;
// 		printf("squere [%d] mendiane\n", squere_nb);
// 	}
// 	while (map->current_phiras++ < map->phiras)
// 	{
// 		squere_nb = rand() % map->width * map->height + 1;
// 		map->squeres[squere_nb]->phiras++;
// 		printf("squere [%d] phiras\n", squere_nb);
// 	}
// 	while (map->current_thystame++ < map->max_thystame)
// 	{
// 		squere_nb = rand() % map->width * map->height + 1;
// 		map->squeres[squere_nb]->thystame++;
// 		printf("squere [%d] thystame\n", squere_nb);
// 	}
// }

// void	generate_stones(t_map *map, t_server *server)
// {
// 	max_linemate = width * height / 5 * server->players_nb;
// 	max_deraumere = width * height / 8 * server->players_nb;
// 	max_sibur = width * height / 7 * server->players_nb;
// 	max_mendiane = width * height / 10 * server->players_nb;
// 	max_phiras =  width * height / 7 * server->players_nb;
// 	max_thystame = server->players_nb * 1.5;

// 	add_stones_1(map);
// 	add_stones_2(map);
// }
