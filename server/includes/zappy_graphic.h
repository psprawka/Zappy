/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_graphic.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:20:32 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 23:17:40 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_GRAPHIC_H
# define ZAPPY_GRAPHIC_H


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
void				notify_broadcast(t_player *player, char *msg, t_server *server);
void				notify_starve(t_player *player, t_server *server);
void				resource_drop(t_player *player, uint8_t resource, t_server *server);
void				notify_kick(t_player *player, t_server *server);
void				lay_egg(t_player *player, t_server *server);
void				resource_pickup(t_graphic *client, t_server *server);
void				start_incantation(t_player *player, t_server *server);
void				end_incantation(t_player *player, t_server *server, int result);
void				send_inventory(t_player *player, t_server *server);
void				player_level(t_player *player, t_server *server);
void				notify_new_player(t_player *player, t_server *server);
void				player_position(t_player *player, t_server *server);

//		MAP

void				send_block_contents(int x, int y, t_graphic *client, t_server *server);
void				map_size(t_server *server);
void				send_teams(t_server *server);

//		EGG
void				notify_connectegg(t_player *player, t_server *server);
void				notify_hatchegg(t_player *player, t_server *server);

//		SERVER INFO
void				unknown_parameter(void);
void				game_over(t_team *team, t_server server);
void				send_timeunit(t_graphic *client, t_server *server);
void				server_message(t_server *server, char *message);
void				unknown_command(void);

//		TEAMS
void				send_teams(t_server *server);

#endif
