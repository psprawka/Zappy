/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:39:30 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 23:59:43 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZAPPY_MAP_H
# define ZAPPY_MAP_H

#include "zappy.h"

typedef struct s_player t_player;

typedef struct	s_square
{
	// int 		food;
	// int			linemate;
	// int			deraumere;
	// int			sibur;
	// int			mendiane;
	// int			phiras;
	// int			thystame;

	int		ressources[7];
	t_player	 **players;
	
}				t_square;

typedef struct	s_map
{
	int			width;
	int			height;
	t_square	***squares;

	uint8_t		max_food;
	uint8_t		max_linemate;
	uint8_t		max_deraumere;
	uint8_t		max_sibur;
	uint8_t		max_mendiane;
	uint8_t		max_phiras;
	uint8_t		max_thystame;
	uint8_t		current_food;
	uint8_t		current_linemate;
	uint8_t		current_deraumere;
	uint8_t		current_sibur;
	uint8_t		current_mendiane;
	uint8_t		current_phiras;
	uint8_t		current_thystame;
}				t_map;

#endif