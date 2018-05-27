/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_server.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:30:53 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/26 19:02:17 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_SERVER_H
# define ZAPPY_SERVER_H

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

# define	BUFF_SIZE		64
# define	MAX_CLIENT_FD	10
# define	SERVPASSWD		"polcia"
# define 	DEF_COLOR		CYAN

typedef struct	s_client
{
	int		sockfd;
	char	*color;
	char	*name;
	char	*room;
}				t_client;

typedef struct	s_square
{

	
}				t_square;

typedef struct	s_player
{
	
}				t_player;

typedef struct	s_map
{
	int	x;
	int	y;
	t_square	**map;
}				t_map;

typedef struct	s_team
{
	char	*name;
	int		hlvl;	//the highest lvl
	int		players;
}				t_team;

typedef struct	s_server
{
	t_player	**players;
	t_map		*map;
	t_team		**teams;
	float		time;
	int			min_players;
	int			players_nb;
}				t_server;


/*
**	init_structs.c
*/
t_map	*init_map();
void	init_server(t_server *serv);

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
void	process_data(int currfd, int sockfd, fd_set *client_fds);

/*
**	server.c
*/
void	check_select_fds(fd_set *client_fds, int sockfd);
void	runserver(fd_set client_fds, int sockfd);
int		server_socket(int port);
int		main(int ac, char **av);

/*
**	struct sockaddr_in
**	{
**		sa_family_t sin_family; 		ddress Family/rodzina adresów
**		uint16_t sin_port;				Port number/numer portu
**		struct in_addr sin_addr;		Internet address/adres internetowy
**		unsigned char sin_zero[8];		Pad bytes/ dla zachowania rozmiaru struct sockaddr
**	};
**
**	my_addr.sin_port = 0; // wybierz losowo nieu˙zywany port
**	my_addr.sin_addr.s_addr = INADDR_ANY; // u˙zyj mojego adresu IP
**
**	FD_SETSIZE is 1024
*/

#endif
