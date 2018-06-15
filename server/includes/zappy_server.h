/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_server.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:30:53 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 18:01:34 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_SERVER_H
# define ZAPPY_SERVER_H

#include "zappy.h"

typedef struct s_team			t_team;
typedef struct s_pevent			t_pevent;
typedef struct s_pdeath			t_pdeath;
typedef struct s_graphic_list	t_graphic_list;

typedef struct	s_server
{
	int				sockfd;
	char			*buff;
	struct timeval	time;
	int				timeunit;
	int				port;
	int				max_team_players;
	int				teamcount;
	t_graphic_list	*graph_list;
	t_player		**players;
	t_map			*map;
	t_team			**teams;
	t_pevent		*events;
	t_pdeath		*deaths;

}				t_server;

#endif
