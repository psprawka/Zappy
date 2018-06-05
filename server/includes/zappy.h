/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:39:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 19:22:29 by asyed            ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/event.h>
# include <sys/time.h>


# include "zappy_commands.h"
# include "zappy_map.h"
# include "zappy_server.h"

# define	BUFF_SIZE		64
# define	DEF_COLOR		CYAN

# define	MSG_WELCOME		"WELCOME!\n"
# define	MSG_NOCOMMAND	"This command doesn't exist!\n"
# define	MSG_FULLTEAM	"0"
# define	MSG_NOTEAM		"This team doesn't exist. Reenter your team name.\n"
# define	MSG_OK			"ok\n"
# define	MSG_KO			"ko\n"
# define	MSG_DEATH		"death\n"

# define	NORTH			1
# define	EAST			2
# define	SOUTH			4
# define	WEST			8
// # define	SAMEPOS(x,y) ((x).x == (y).x && (x).y == (y).y)


enum e_shape
{
	none,
	square,
	rectangle,
};

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
	int			players;
}				t_team;

typedef struct s_inventory
{
	int			linemate;
	int			deraumere;
	int			sibur;
	int			mendiane;
	int			phiras;
	int			thystame;
	int 		food;
}				t_inventory;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct	s_player
{
	int				fd;
	t_team			*team;
	int				level;
	int				direction;
	t_inventory		inv;
	int				see_range;
	t_square		*position;
	// t_position		*position;
	int				lifetime;
	int				requests;
}				t_player;

/*
**	init_structs.c
*/
t_map		*init_map(void);
t_inventory	*init_inv(void);
t_player	*init_player(int sockfd, t_server *server);
int			init_server(t_server *serv);

/*
**	randomize.c
*/
int			rand_direction(void);
t_square	*rand_position(t_map *map);

/*
**	teams.c
*/
int		get_team_name(t_player *player, t_server *serv, char *msg);

/*
**	player.c
*/
void	player_quit(t_player *player, t_server *serv);

/*
**	tools.c
*/
void	tools_world_dimensions(t_player *player, t_server *server);
int		xytocoordinate(int x, int y);

/*
**	server_parse.c
*/
int		error(int errnb, char *msg, bool ifexit);
void	parse_args_serv(int ac, char **av, t_server *serv);

/*
**	options.c
*/
int 			opt_dimentions(char **av, int *i);
int				opt_min_players(char **av, int *i);
struct timeval	opt_time(char **av, int *i);
t_team			**opt_teams(char **av, int *i, t_server *server);

/*
**	server_process.c
*/
int		process_data(t_player *player, t_server *serv);

/*
**	server.c
*/
void	check_select_fds(t_server *server, fd_set *client_fds, int sockfd);
// void	runserver(fd_set client_fds, t_server *server, int sockfd);
int		runserver(int server_fd, t_server *server);
int		server_socket(int port);
int		main(int ac, char **av);


#endif