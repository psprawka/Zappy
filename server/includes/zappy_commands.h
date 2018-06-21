/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:08:13 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 08:52:46 by psprawka         ###   ########.fr       */
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

typedef struct	s_events
{
	char	*msg;
	int		time;
	int		(*fct)(void *entity, char *msg);
}				t_events;


typedef struct	s_vector
{
	int		x;
	int		y;
}				t_vector;

/*
**	fork/eggs.c
*/
int				handle_egg(t_player *player);

//		BROADCAST UTILS
int				calcul_square(t_vector *direction);
// int				mesage_from(t_map *map, t_player *sender, t_player *receiver);
// void			send_message_to_others(void *entity, char *msg, char *msg);
// void		send_message_to_others(t_player *sender, t_player *receiver, char *msg);

int				command_advance(void *entity, char *msg);
int				command_broadcast(void *entity, char *msg);
int				command_connect_nbr(void *entity, char *msg);
int				command_death(void *entity, char *msg);
int				command_fork(void *entity, char *msg);
int				command_hatch(void *entity, char *msg);
int				command_inventory(void *entity, char *msg);
int				command_kick(void *entity, char *msg);
int				command_left(void *entity, char *msg);
int				command_incantation(void *entity, char *msg);
int				command_levelup(void *entity, char *msg);
int				command_put(void *entity, char *msg);
int				command_right(void *entity, char *msg);
int				command_take(void *entity, char *msg);
int				command_eat(void *entity, char *msg);
int				command_egg_death(void *entity, char *msg);

//		SEE UTILS
int				command_see(void *entity, char *msg);
void			rotation90(int *x, int *y);
void			rotation180(int *x, int *y);
void			rotation270(int *x, int *y);
void			put_player_buffer(int nbr_players, int *first);
void			put_ressources_buffer(t_square *square, int nbr_players, int first);



#endif
