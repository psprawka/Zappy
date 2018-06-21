/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 21:18:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 05:38:50 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_server	g_server;

char	*g_ressources[8] = {
	"food",
	"linemate",
	"deraumere",
	"sibur",
	"mendiane",
	"phiras",
	"thystame",
	NULL
};

/*
**	Those two global variables are connected to each other based on client fd,
**	for example:
**
**	1. Clientfd == 5 and a client is an ai player:
**		  g_client_type[5] = T_PLAYER | g_entity[5] = t_player *player_struct;
**	2. Clientfd == 54 and a client is a graphical client:
**		  g_client_type[54] = T_GRAPHIC | g_entity[54] = t_gui *gui_struct;
**	3. Clientfd == 27 and a client just connected - we don't know its type:
**		  g_client_type[27] = T_NONDEF | g_entity[27] = NULL;
**
**	Since variables are global, option 3 is default.
**
**	----------------------------------------------------------------------------
**
**	How to use it when it comes to coding?
**	Once you have an active fd check in g_client_type what's client's type
** 	(NONDEF, PLAYER, GRAPHIC), then based of it's type cast void * to proper
**	struct type.
**
**	g_entity[fd] variable is equivalent to g_server.players[fd] variable OR
**	to a node holding graphical fd in gui linked list.
*/
uint8_t 		g_client_type[FD_SETSIZE];
void			*g_entity[FD_SETSIZE];

/*
**	Main_game_loop is a place where the game happenes.
**	We have two fd_sets:
**	- g_server.client_fds that holds all fds used in a game.
**	- select_fds that select will use and set to only active sockets.
**	In order to allow select work correctly on all avaliable fds in the game,
**	client_fds set has to be copied to select_fds BEFORE EVERY select call.
**
**	Select function unblocks ("breaks") EITHER when any fd becomes active
**	and data is set via socket OR function timeouts. Select timeouts when
**	values in alarm timeval struct are set to 0. When alarm is set to NULL,
**	select blocks until any fd becomes active.
**
**	Inside while loop all active fds are checked. If data comes form server
**	socket it means that new player tries to connect thus fuction new_client
**	is called. Otherwise client is know, thus function handle_recv is called.
**
**	After checking all active fds, main_game_loop:
**	-> execute all events that are happening or should already happen.
**	-> set timeout for next select call based on first event in events queue.
**	-> copies all used fds to select_fds.
**
**	If select returns negative number, error message is sent and EXIT_FAILURE
**	value is returned
*/
int		main_game_loop(void)
{
	int				i;
	fd_set			select_fds;
	struct timeval	*alarm;

	select_fds = g_server.client_fds;
	alarm = NULL;
	while (select(FD_SETSIZE, &select_fds, NULL, NULL, alarm) > -1)
	{
		i = -1;
		while (++i < FD_SETSIZE + 1)
		{
			if (FD_ISSET(i, &select_fds))
				i == g_server.serverfd ? new_client() : handle_recv(i);
		}
		generate_ressource(rand() % 7);
		execute_events();
		if (alarm)
			free(alarm);
		alarm = set_time_alarm();
		select_fds = g_server.client_fds;

		// if (g_client_type[5] != 0)
		//  break;
	}
	if (alarm)
		free(alarm);
		
	// bzero(&g_server, sizeof(t_server));
	free_server();
	// printf("falling asleep\n");
	// sleep(100);
	// free(g_entity);
	return (error(0, "Select [main_game_loop]", true));
}

/*
**	A constructor executed before main function.
*/
__attribute__((constructor))void init(void)
{
	srand(time(NULL));
}

/*
**	In main function:
**	-> global server struct is creted and initialized,
**	-> arguments given in command line are parsed,
**	-> game map is initialized,
**	-> server socket is initialized (init_server_socket function),
**	-> serverfd is added to g_server.client_fds variable needed in select
**		function that holds all fds used in a game,
**	-> main_game_loop function which runs a game is exectuted.
*/
int		main(int ac, char **av)
{
	if (init_server() == EXIT_FAILURE ||
		parse_args(ac, av) == EXIT_FAILURE ||
		init_map() == EXIT_FAILURE ||
		init_server_socket() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (listen(g_server.serverfd, FD_SETSIZE) == -1)
		return (error(0, "Listen [main]", true));
	ft_bzero(&g_server.client_fds, sizeof(fd_set));
	FD_SET(g_server.serverfd, &g_server.client_fds);
	return (main_game_loop());
}
