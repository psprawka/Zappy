/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:08:13 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 13:04:12 by tle-huu-         ###   ########.fr       */
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


typedef struct	s_action_arg
{
	int		ressource;
	char	*message;
}				t_action_arg;

typedef struct	s_commands
{
	char				*msg;
	int					delay;
	// int		(*fct)(t_player *player, t_server *serv, t_action_arg *arg);
	int					(*fct)(void *object, t_action_arg *arg);

}				t_commands;


//		BROADCAST UTILS
// int				calcul_square(t_vector *direction);
// int				mesage_from(t_map *map, t_player *sender, t_player *receiver);
// void			send_message_to_others(t_player *player, t_server *server, char *msg);
void	send_message_to_others(t_player *sender, t_player *receiver, t_server *server, char *msg);

int		command_advance(void *object, t_action_arg *arg);
int		command_broadcast(void *object, t_action_arg *arg);
int		command_connect_nbr(void *object, t_action_arg *arg);
int		command_death(void *object, t_action_arg *arg);
int		command_fork(void *object, t_action_arg *arg);
int		command_inventory(void *object, t_action_arg *arg);
int		command_kick(void *object, t_action_arg *arg);
int		command_left(void *object, t_action_arg *arg);
int		command_levelup(void *object, t_action_arg *arg);
// int	command_put(void *object, t_action_arg *argsource);
int		command_put(void *object, t_action_arg *arg);
int		command_right(void *object, t_action_arg *arg);
int		command_see(void *object, t_action_arg *arg);
int		command_take(void *object, t_action_arg *arg);
// int	command_take(t_player *player, t_server *serv, int ressource);


#endif
