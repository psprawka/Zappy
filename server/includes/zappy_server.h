/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_server.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:30:53 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 17:21:36 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_SERVER_H
# define ZAPPY_SERVER_H

#include "zappy.h"

typedef struct s_team	t_team;
typedef struct s_pevent	t_pevent;
typedef struct s_queue	t_queue;

typedef struct	s_server
{
	t_graphic_list	*graph_list;
	t_player		**players;
	t_map			*map;
	t_team			**teams;
	t_pevent		*events;
	char			*buff;
	struct timeval	time;
	int				timeunit;
	int				port;
	int				max_team_players;
	int				teamcount;
}				t_server;

#endif
