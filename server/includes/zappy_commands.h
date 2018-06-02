/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:08:13 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 04:37:50 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_COMMANDS_H
# define ZAPPY_COMMANDS_H

#include "zappy.h"

typedef struct s_player t_player;
typedef struct s_server t_server;

typedef struct	s_commands
{
	char	*msg;
	int		delay;
	void	(*fct)(t_player *player, t_server *serv);
}				t_commands;

typedef struct	s_event
{
	struct timeval	delaytime;
	t_player		*player;
	void			(*fct)(t_player *player, t_server *serv);
}				t_event;

void	command_advance(t_player *player, t_server *serv);
void	command_broadcast(t_player *player, t_server *serv);
void	command_connect_nbr(t_player *player, t_server *serv);
void	command_death(t_player *player, t_server *serv);
void	command_fork(t_player *player, t_server *serv);
void	command_inventory(t_player *player, t_server *serv);
void	command_kick(t_player *player, t_server *serv);
void	command_left(t_player *player, t_server *serv);
void	command_levelup(t_player *player, t_server *serv);
void	command_put(t_player *player, t_server *serv);
void	command_right(t_player *player, t_server *serv);
void	command_see(t_player *player, t_server *serv);
void	command_take(t_player *player, t_server *serv);

#endif