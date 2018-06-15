/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:39:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 13:15:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_H
# define ZAPPY_H

# include <unistd.h>
# include <stdio.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <errno.h>
# include <term.h>
# include <curses.h>
# include "libft.h"
# include <string.h>

# include "list.h"
# include "queue.h"
# include "zappy_commands.h"
# include "zappy_map.h"
# include "zappy_server.h"
# include "zappy_pqueue.h"
# include "zappy_graphic.h"

t_server	*g_server;

# define	BUFF_SIZE		64
# define	SERV_BUFF_SIZE	2048
# define	DEF_COLOR		CYAN

# define	MSG_WELCOME		"WELCOME!\n"
# define	MSG_NOCOMMAND	"This command doesn't exist!\n"
# define	MSG_FULLTEAM	"0\n"
# define	MSG_NOTEAM		"This team doesn't exist. Reenter your team name.\n"
# define	MSG_OK			"ok\n"
# define	MSG_KO			"ko\n"
# define	MSG_DEATH		"death\n"

# define	MAX_REQUEST_NB	10

# define	NORTH			1
# define	EAST			2
# define	SOUTH			4
# define	WEST			8

# define 	T_NONDEF		0
# define 	T_PLAYER		1
# define 	T_GRAPHICAL		2

# define	FOOD			0
# define	LINEMATE		1
# define	DERAUMERE		2
# define	SIBUR			3
# define	MENDIANE		4
# define	PHIRAS			5
# define	THYSTAME		6

extern t_commands g_commands[];

typedef struct	s_vector
{
	int		x;
	int		y;
}				t_vector;

typedef struct	s_opt
{
	char		opt;
	int			(*fct)(char **av, int *i, t_server *server);
}				t_opt;

typedef struct	s_egg
{
	t_team		*team;
	int			hatched;
	int			x;
	int			y;
}				t_egg;

typedef struct	s_client
{
	int		sockfd;
	char	*color;
	char	*name;
	char	*room;
}				t_client;

typedef struct	s_team
{
	char		*name;
	int			hlvl;	//the highest lvl
	int			max_players;
	int			connected;
	int			allowed_eggs;
	t_queue		*eggqueue;

}				t_team;

typedef struct s_inventory
{
	// int 		food;
	// int			linemate;
	// int			deraumere;
	// int			sibur;
	// int			mendiane;
	// int			phiras;
	// int			thystame;

	int		inventory[7];

}				t_inv;

typedef struct	s_player
{
	int				fd;
	t_team			*team;
	int				level;
	int				direction;
	// t_inv			*inv;
	int				see_range;
	int				type;
	int				x;
	int				y;
	int				inventory[7];
	struct timeval	*last_request;
	int				requests_nb;
}				t_player;

/*
**	generator.c
*/
void		generate_food(t_map *map, t_server *server);
void		add_stones_1(t_map *map);
void		add_stones_2(t_map *map);
void		generate_stones(t_map *map, t_server *server);

/*
**	graphical.c
*/
int			if_graphical(t_server *server, t_player *player, char *msg);
/*
**	init_structs.c
*/
int			init_square(t_square *square);
int			init_map(t_server *server);
t_player	*init_player(int sockfd, t_server *server);
int			init_server(t_server *serv);

/*
**	opt.c
*/
int			opt_port(char **av, int *i, t_server *server);
int			opt_dimentions(char **av, int *i, t_server *server);
int			opt_max_players(char **av, int *i, t_server *server);
int			opt_time(char **av, int *i, t_server *server);
int			opt_teams(char **av, int *i, t_server *server);

/*
**	parse.c
*/
int			error(int errnb, char *msg, bool ifexit);
int			check_args(t_server *server);
int			parse_args_serv(int ac, char **av, t_server *server);

/*
**	player.c
*/
void		player_quit(t_player *player, t_server *serv);
void		new_player(t_server *serv, fd_set *client_fds, int sockfd);

/*
**	pevents/
*/
t_pevent 		*create_pevent(t_player *player, struct timeval *event_time, int itable, char *msg);
int				push_pevent(t_pevent **head, t_pevent *new);
int				add_pevent(t_server *serv, t_player *player, int itable, char *msg);
t_pevent		*pop_pevent(t_pevent **head);
struct timeval	*top_pevent(t_pevent *head);
void			free_pevent(t_pevent *to_free);


/*
**	pdeaths/
*/
t_pdeath		*create_pdeath(void *object, struct timeval *death_time);
int				push_pdeath(t_pdeath **head, void *object, struct timeval *death_time);
t_pdeath		*pop_pdeath(t_pdeath **head);
struct timeval	*top_pdeath(t_pdeath *head);

/*
**	randomize.c
*/
int			rand_direction(void);
void		rand_position(t_player *player, t_map *map);

/*
**	server_process.c
*/
int			parse_recv(t_player *player, t_server *server, char *msg);
int			process_data(t_player *player, t_server *serv, fd_set *client_fds);

/*
**	server.c
*/
int			execute_deaths(t_server *server);
int			execute_events(t_server *server);
int			runserver(fd_set client_fds, t_server *server, int sockfd);
int			server_socket(int port);

/*
**	teams.c
*/
int			get_team_name(t_player *player, t_server *serv, char *msg);

/*
**	time.c
*/
int			time_compare(struct timeval *first, struct timeval *second);

/*
**	tools.c
*/
int			tools_world_dimensions(t_player *player, t_server *serv);
void		print_map(t_server *server, int x, int y);
int			hash_function(char *ressource);
int			init_action_arg(t_action_arg *arg, int ressource, char *message);

/*
**	eggs
*/
t_egg				*new_egg(t_team *team, int x, int y);




#endif
