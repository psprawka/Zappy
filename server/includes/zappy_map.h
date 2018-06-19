/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:39:30 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 08:02:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZAPPY_MAP_H
# define ZAPPY_MAP_H

#include "zappy.h"

typedef struct s_player t_player;

/*
**	resources[7]:
**	0 food;
**	1 linemate;
**	2 deraumere;
**	3 sibur;
**	4 mendiane;
**	5 phiras;
**	6 thystame;
*/

typedef struct	s_square
{
	int			ressources[7];
	t_player	 **players;
}				t_square;

typedef struct	s_map
{
	int			width;
	int			height;
	t_square	***squares;
	uint8_t		max_ressources[7];
	uint8_t		current_ressources[7];
}				t_map;

#endif
