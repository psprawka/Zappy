/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:39:30 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/01 15:00:58 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZAPPY_MAP_H
# define ZAPPY_MAP_H

#include "zappy.h"

typedef struct s_player t_player;

typedef struct	s_square
{
	int			linemate;
	int			deraumere;
	int			sibur;
	int			mendiane;
	int			phiras;
	int			thystame;
	int 		food;
	t_player	 **players;
	
}				t_square;

typedef struct	s_map
{
	int			height;
	int			width;
	t_square	**map;
	
}				t_map;

#endif