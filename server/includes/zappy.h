/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:39:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/31 17:14:02 by psprawka         ###   ########.fr       */
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

# include "zappy_commands.h"
# include "zappy_map.h"
# include "zappy_server.h"

# define	BUFF_SIZE		64
# define	DEF_COLOR		CYAN

# define	MSG_WELCOME		"WELCOME!"
# define	MSG_NOCOMMAND	"This command doesn't exist!"
# define	MSG_FULLTEAM	"0"
# define	MSG_NOTEAM		"This team doesn't exist. Reenter your team name."
# define	MSG_OK			"ok"
# define	MSG_KO			"ko"
# define	MSG_DEATH		"death"

# define	NORTH			1
# define	EAST			2
# define	SOUTH			4
# define	WEST			8

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
	
}				t_inv;

typedef struct	s_player
{
	int			fd;
	t_team		*team;
	int			level;
	int			direction;
	t_inv		*inv;
	int			see_range;
	int			position;
	int			lifetime;
	int			requests;
	
}				t_player;

/*
**	init_structs.c
*/
t_map		*init_map(void);
t_inv		*init_inv(void);
t_player	*init_player(int sockfd, t_server *server);
void		init_server(t_server *serv);

/*
**	randomize.c
*/
int rand_direction(void);
int rand_position(t_map *map);

/*
**	teams.c
*/
void	get_team_name(t_player *player, t_server *serv, char *msg);

/*
**	player.c
*/
void	player_quit(t_player *player, t_server *serv);

/*
**	tools.c
*/
void	tools_world_dimensions(t_player *player, t_server *server);

/*
**	server_parse.c
*/
void	error(int errnb, char *msg, bool ifexit);
void	parse_args_serv(int ac, char **av, t_server *serv);

/*
**	options.c
*/
int 	opt_dimentions(char **av, int *i);
int		opt_min_players(char **av, int *i);
int		opt_time(char **av, int *i);
t_team	**opt_teams(char **av, int *i);

/*
**	server_process.c
*/
void	process_data(t_player *player, t_server *serv, fd_set *client_fds);

/*
**	server.c
*/
void	check_select_fds(t_server *server, fd_set *client_fds, int sockfd);
void	runserver(fd_set client_fds, t_server *server, int sockfd);
int		server_socket(int port);
int		main(int ac, char **av);


#endif