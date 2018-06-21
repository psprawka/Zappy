/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_graphic.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:20:32 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:53:42 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_GRAPHIC_H
# define ZAPPY_GRAPHIC_H

typedef struct s_egg	t_egg;

//		PLAYERS ACTIONS
void			notify_broadcast(t_player *player, char *msg);
void			notify_starve(t_player *player);
void			notify_ressource_drop(t_player *player, uint8_t ressource);
void			notify_kick(t_player *player);
void			notify_lay_egg(t_player *player);
void			notify_ressource_pickup(t_player *player, int ressource);
void			notify_start_incantation(t_player *player);
void			notify_end_incantation(t_player *player, int result);
void			send_inventory(int fd, t_player *player);
void			notify_player_level(int fd, t_player *player);
void			notify_new_player(int fd, t_player *player);
void			notify_player_position(int fd, t_player *player);

//		EGG
void			notify_connect_egg(t_egg *egg);
void			notify_starve_egg(t_egg *egg);
void			notify_hatch_egg(t_egg *egg);
void			notify_egg_laid(t_player *player, t_egg *egg);

//		MAP
void			send_block_contents(int fd, int x, int y);
void			send_mapcontents(int fd);
void			map_size(int fd);
void			send_teams(int fd);


//		SERVER INFO
void			notify_unknown_parameter(void);
void			notify_game_over(t_team *team);
void			send_timeunit(int fd);
void			notify_server_message(char *message);
void			notify_unknown_command(void);

//		SEND GREETING (WHEN GRAPHIC CONNET)
void			send_graphic_greeting(int fd);

#endif
