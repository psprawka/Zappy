/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:08:13 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 00:22:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_COMMANDS_H
# define ZAPPY_COMMANDS_H

#include "zappy.h"

typedef struct s_player		t_player;
typedef struct s_server		t_server;
typedef struct s_vector		t_vector;
typedef struct s_map		t_map;
typedef struct s_graphic	t_graphic;

typedef struct	s_commands
{
	char	*msg;
	int		delay;
	int		(*fct)(t_player *player, t_server *serv);
}				t_commands;

//		BROADCAST UTILS
// int				calcul_square(t_vector *direction);
// int				mesage_from(t_map *map, t_player *sender, t_player *receiver);
// void			send_message_to_others(t_player *player, t_server *server, char *msg);
void			send_message_to_others(t_player *sender, t_player *receiver, t_server *server, char *msg);

int	command_advance(t_player *player, t_server *serv);
int	command_broadcast(t_player *player, t_server *serv);
int	command_connect_nbr(t_player *player, t_server *serv);
int	command_death(t_player *player, t_server *serv);
int	command_fork(t_player *player, t_server *serv);
int	command_inventory(t_player *player, t_server *serv);
int	command_kick(t_player *player, t_server *serv);
int	command_left(t_player *player, t_server *serv);
int	command_levelup(t_player *player, t_server *serv);
// int	command_put(t_player *player, t_server *serv, int ressource);
int	command_put(t_player *player, t_server *serv);
int	command_right(t_player *player, t_server *serv);
int	command_see(t_player *player, t_server *serv);
int	command_take(t_player *player, t_server *serv);
// int	command_take(t_player *player, t_server *serv, int ressource);


#endif
