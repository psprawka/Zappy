/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_client.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 03:41:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 08:46:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_CLIENT_H
# define ZAPPY_CLIENT_H

# include "zappy.h"

typedef struct	s_team	t_team;

typedef struct	s_level
{
	int		level;
	int		players_nb;
	int		resources[7];
}				t_level;


typedef struct	s_player
{
	int				fd;
	t_team			*team;
	int				level;
	int				direction;
	int				x;
	int				y;
	int				inventory[7];
	struct timeval	*last_request;
	int				requests_nb;
	bool			incantation;

}				t_player;

#endif
