/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_graphic.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:20:32 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/17 23:52:50 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_GRAPHIC_H
# define ZAPPY_GRAPHIC_H

typedef struct s_team	t_team;


typedef struct		s_graphic_list
{
	int				fd;
	struct s_list	*next;
}					t_graphic_list;



t_graphic_list		*glist_new(int fd);
void				glist_add(t_graphic_list **alst, t_graphic_list *nw);
void				glist_add_end(t_graphic_list **alst, t_graphic_list *nw);
int					glist_length(t_graphic_list *list);


//		PLAYERS ACTIONS
void				notify_broadcast(int fd, t_player *player, char *msg);
void				notify_starve(int fd, t_player *player);
void				ressource_drop(int fd, t_player *player, uint8_t resource);
void				notify_kick(int fd, t_player *player);
void				lay_egg(int fd, t_player *player);
void				ressource_pickup(int fd, t_player *player, int ressource);
void				start_incantation(int fd, t_player *player);
void				end_incantation(int fd, t_player *player, int result);
void				send_inventory(int fd, t_player *player);
void				player_level(int fd, t_player *player);
void				notify_new_player(int fd, t_player *player);
void				player_position(int fd, t_player *player);

//		MAP

void				send_block_contents(int fd, int x, int y);
void				send_mapcontents(int fd);
void				map_size(int fd);
void				send_teams(int fd);

//		EGG
void				notify_connectegg(int fd, t_egg *egg);
void				notify_hatchegg(int fd, t_egg *egg);
void				notify_egg_laid(int fd, t_player *player, t_egg *egg);
void				notify_starve_egg(int fd, t_egg *egg);


//		SERVER INFO
void				unknown_parameter(int fd);
void				game_over(int fd, t_team *team);
void				send_timeunit(int fd);
void				server_message(int fd, char *message);
void				unknown_command(int fd);

//		TEAMS
void				send_teams(int fd);

//		SEND GREETING (WHEN GRAPHIC CONNET)
void				send_graphic_greeting(int fd);


#endif
